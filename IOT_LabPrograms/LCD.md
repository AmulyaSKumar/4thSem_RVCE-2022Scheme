#  Arduino Uno with LCD to Display System Status 

## Aim
Use Arduino Uno to interface between a 4D LCD display and a computer's USB port to show various information on the LCD screen, including system stats like network utilization, CPU load, and disk space.

## Components Required
- Arduino Uno
- 16x2 LCD display
- Breadboard
- Jumper Wires

## Code

### Arduino Code

```cpp

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
bool showNetworkAndCPU = true;

void setup() {
    lcd.begin();
    lcd.backlight();
    Serial.begin(9600);
}

void loop() {
    if (Serial.available() > 0) {
        String data = Serial.readStringUntil('\n');
        int separatorIndex = data.indexOf(',');
        String line1 = data.substring(0, separatorIndex);
        String line2 = data.substring(separatorIndex + 1);

        lcd.clear();
        
        if (showNetworkAndCPU) {
            lcd.setCursor(0, 0);
            lcd.print(line1);  // Network on 1st row
            lcd.setCursor(0, 1);
            lcd.print(line2);  // CPU on 2nd row
        } else {
            lcd.setCursor(0, 0);
            lcd.print(line2);  // Memory on 1st row
            lcd.setCursor(0, 1);
            lcd.print(line1);  // Disk on 2nd row
        }
        
        showNetworkAndCPU = !showNetworkAndCPU;  // Toggle between views
        delay(1000);  // 1 second delay before switching
    }
}
```

##Python file(Run as Administrator)
```python
import psutil
import serial
import time

ser = serial.Serial('COM3', 9600)

def get_system_stats():
    # Get system stats
    cpu = psutil.cpu_percent(interval=1)
    memory = psutil.virtual_memory().percent
    disk = psutil.disk_usage('/').percent
    net = psutil.net_io_counters().bytes_sent + psutil.net_io_counters().bytes_recv
    
    net_and_cpu = f"Net: {net}B, CPU: {cpu}%"
    mem_and_disk = f"Mem: {memory}%, Disk: {disk}%"
    
    return net_and_cpu, mem_and_disk

while True:
    net_and_cpu, mem_and_disk = get_system_stats()
    
    ser.write(f"{net_and_cpu}\n".encode('utf-8'))  # Send Network and CPU data
    time.sleep(1)  # Pause for 1 second
    
    ser.write(f"{mem_and_disk}\n".encode('utf-8'))  # Send Memory and Disk data
    time.sleep(1)
```
