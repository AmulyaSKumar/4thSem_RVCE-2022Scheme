```markdown
# Arduino Pulse Sensor with LCD Experiment
====================================================

## Aim:
---------
To read and display the heart rate using a Pulse Sensor connected to an Arduino board and show the results on an LCD.

## Components Required:
------------------------
- 1 x Arduino Uno
- 1 x Pulse Sensor
- 1 x 16x2 LCD
- 1 x 10kΩ potentiometer (for LCD contrast)
- Jumper wires
- Breadboard

## Installing LiquidCrystal and PulseSensor Playground Library
---------------------------------------------------------
1. **Open Arduino IDE**.
2. **Go to**: `Sketch` > `Include Library` > `Manage Libraries`.
3. **In the Library Manager**, type "LiquidCrystal" and "PulseSensor Playground" in the search bar.
4. If it is not installed, click on the **Install** button.

## Connections
-----------
### Pulse Sensor Connections:

- Connect the Pulse Sensor's VCC pin to the **5V** pin on the Arduino.
- Connect the Pulse Sensor's GND pin to the **GND** pin on the Arduino.
- Connect the Pulse Sensor's signal pin to **analog pin A0** on the Arduino.

### LCD Connections:

- Connect the LCD as follows:
  - **VCC** to **5V** on Arduino
  - **GND** to **GND** on Arduino
  - **SDA** to **A4** on Arduino
  - **SCL** to **A5** on Arduino
  - Adjust the potentiometer for **LCD contrast**.

## Code for Pulse Sensor with LCD
--------------------------------
```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <PulseSensorPlayground.h>

// Create an instance of the PulseSensorPlayground class
PulseSensorPlayground pulseSensor;

// Create an instance of the LCD class
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 columns, 2 rows

const int pulsePin = A0; // Analog pin where the pulse sensor is connected

void setup() {
  Serial.begin(9600);
  
  // Initialize the PulseSensorPlayground library
  pulseSensor.analogInput(pulsePin);
  pulseSensor.setThreshold(550); // Set the threshold for detecting beats
  pulseSensor.begin();
  
  // Initialize the LCD
  lcd.begin();
  lcd.backlight(); // Turn on the backlight
  lcd.print("Heart Rate: ");
}

void loop() {
  // Read the value from the sensor
  int bpm = pulseSensor.getBeatsPerMinute();
  
  // Print the heart rate if it is valid
  if (bpm > 0) {
    lcd.setCursor(0, 1); // Set cursor to the second row
    lcd.print(bpm);
    lcd.print(" bpm     "); // Add spaces to clear previous values
  } else {
    lcd.setCursor(0, 1);
    lcd.print("No pulse    ");
  }

  // Delay for 1 second
  delay(1000);
}
```

## Output
-----
- The LCD displays the heart rate in beats per minute (bpm).
- If no pulse is detected, it shows "No pulse".

## Additional Code for Pulse Sensor (Without LCD)
-----------------------------------------------
```cpp
#include <PulseSensorPlayground.h>

// Create an instance of the PulseSensorPlayground class
PulseSensorPlayground pulseSensor;

const int pulsePin = A0; // Analog pin where the pulse sensor is connected

void setup() {
  Serial.begin(9600);
  
  // Initialize the PulseSensorPlayground library
  pulseSensor.analogInput(pulsePin);
  pulseSensor.setThreshold(550); // Set the threshold for detecting beats
  pulseSensor.begin();
}

void loop() {
  // Read the value from the sensor
  int signal = pulseSensor.getBeatsPerMinute();
 
  // Print the heart rate if it is valid
  if (signal > 0) {
    Serial.print("Heart Rate: ");
    Serial.print(signal);
    Serial.println(" bpm");
  } else {
    Serial.println("No pulse detected.");
  }

  // Delay for 1 second
  delay(1000);
}
```

## Applications
-------------
- Health monitoring systems.
- Fitness devices that provide immediate feedback.
- Educational projects involving sensors and displays.
```