# Smart Lighting Application using LDR Sensor & Buzzer Interfacing with Raspberry Pi and Connecting to Cloud for Analysis

### Components Required
- **Raspberry Pi** 
- **Light Dependent Resistor (LDR)**
- **Buzzer**
- **LED**
- **Resistors** (e.g., 10kΩ for the LDR)
- **Jumper Wires**
- **Breadboard** (optional, for prototyping)
- **ThingSpeak Account** (for cloud data analysis)

### Purpose
The purpose of this project is to create a smart lighting application that:
- Monitors ambient light using an LDR sensor.
- Activates a buzzer and an LED when the light level is low.
- Sends data to ThingSpeak for remote monitoring and analysis.

### Connection
1. **Connect the LDR:**
   - Connect one end of the LDR to a GPIO pin (e.g., Board pin 22).
   - Connect the other end to the ground (GND) pin.
   - Place a resistor (e.g., 10kΩ) between the GPIO pin and GND to create a voltage divider.

2. **Connect the Buzzer:**
   - Connect the positive terminal of the buzzer to a GPIO pin (e.g., Board pin 24).
   - Connect the negative terminal of the buzzer to the ground (GND) pin.

3. **Connect the LED:**
   - Connect the anode (long leg) of the LED to a GPIO pin (e.g., Board pin 12).
   - Connect the cathode (short leg) of the LED to the ground (GND) pin.
   - Use a resistor (e.g., 220Ω) in series with the LED to limit current.

### Code

#### Basic Code

```python
import time
import RPi.GPIO as GPIO  
import urllib.parse
import http.client

BUZZER_PIN = 33
LDR_PIN = 3
LED = 11

key = ""   # Add ThingSpeak key here

def setup_gpio():
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(BUZZER_PIN, GPIO.OUT)  
    GPIO.setup(LDR_PIN, GPIO.IN)
    GPIO.setup(LED, GPIO.OUT)

def ldr():
    while True:
        ldr_value = GPIO.input(LDR_PIN) 
        
        if ldr_value == 1:
            print("High: Switch on buzzer")
            GPIO.output(BUZZER_PIN, True)
            print("LED ON")
            GPIO.output(LED, True)
        else:
            print("Low: Don't switch on buzzer")
            GPIO.output(BUZZER_PIN, False)
            print("LED OFF")
            GPIO.output(LED, False)
       
        time.sleep(0.3)
       
        LDRData = ldr_value
        BuzzerData = 1 if ldr_value == 1 else 0
       
        params = urllib.parse.urlencode({'field1': LDRData, 'field2': BuzzerData, 'key': key})
        headers = {"Content-type": "application/x-www-form-urlencoded", "Accept": "text/plain"}
        conn = http.client.HTTPConnection("api.thingspeak.com", 80)
        try:
            conn.request("POST", "/update", params, headers)
            response = conn.getresponse()
            print(LDRData)
            print(BuzzerData)
            print(response.status, response.reason)
            data = response.read()
            conn.close()
        except Exception as e:
            print("Connection failed:", e)

if __name__ == "__main__":
    setup_gpio()  # Initialize GPIO once
    try:
        ldr()  # Start the LDR monitoring loop
    except KeyboardInterrupt:
        print("Program interrupted")
    finally:
        GPIO.cleanup()  # Clean up GPIO settings
```
### ThingSpeak Setup
1. **Open ThingSpeak:**
   - Go to [ThingSpeak](https://thingspeak.com) and sign up for a free account or log in if you already have one.

2. **Create a Channel:**
   - Click on the "Channels" tab.
   - Click on "New Channel".
   - Give your channel a name (e.g., "Smart Lighting Data").
   - In "Field 1", enter "LDR_Data".
   - In "Field 2", enter "LED_Data".
   - In "Field 3", enter "Buzzer_Data".
   - Click on "Save Channel".

3. **Take the Channel ID:**
   - After saving, you'll be redirected to the channel view.
   - Copy the **Channel ID** displayed on this page. You will need it for your code.

## **Install `urllib3`:**
   - Open Thonny editor on your Raspberry Pi.
   - Go to `Tools` > `Manage Packages`.
   - Search for `urllib3` and install it.

### Code with ThingSpeak Module

```python
import time
import RPi.GPIO as GPIO  
import thingspeak

BUZZER_PIN = 33
LDR_PIN = 3
LED = 11

channel_id = ""  # Add your ThingSpeak channel ID here
write_key = ""   # Add your ThingSpeak write API key here

def setup_gpio():
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(BUZZER_PIN, GPIO.OUT)  
    GPIO.setup(LDR_PIN, GPIO.IN)
    GPIO.setup(LED, GPIO.OUT)

def ldr():
    channel = thingspeak.Channel(id=channel_id, api_key=write_key)
    while True:
        ldr_value = GPIO.input(LDR_PIN) 
        
        if ldr_value == 1:
            print("High: Switch on buzzer")
            GPIO.output(BUZZER_PIN, True)
            print("LED ON")
            GPIO.output(LED, True)
        else:
            print("Low: Don't switch on buzzer")
            GPIO.output(BUZZER_PIN, False)
            print("LED OFF")
            GPIO.output(LED, False)

        time.sleep(0.3)

        LDRData = ldr_value
        BuzzerData = 1 if ldr_value == 1 else 0

        # Send data to ThingSpeak
        try:
            response = channel.update({'field1': LDRData, 'field2': BuzzerData})
            print(f"LDRData: {LDRData}, BuzzerData: {BuzzerData}")
            print("ThingSpeak Response:", response)
        except Exception as e:
            print("Connection failed:", e)

if __name__ == "__main__":
    setup_gpio()  # Initialize GPIO once
    try:
        ldr()  # Start the LDR monitoring loop
    except KeyboardInterrupt:
        print("Program interrupted")
    finally:
        GPIO.cleanup()  # Clean up GPIO setting
```
### Applications
- **Home Automation**: Automatically turn on lights when ambient light levels are low, enhancing energy efficiency.
- **Smart Lighting Systems**: Integrate with existing smart home systems to control lighting based on occupancy and ambient light.
- **Security Systems**: Use the buzzer as an alarm when darkness is detected, alerting homeowners of potential intrusions.
- **Emergency Lighting**: Activate lights in emergency situations or power outages, providing safety and visibility.
- **Agriculture**: Monitor light conditions in greenhouses, automatically adjusting artificial lighting to optimize plant growth.
- **Smart Surveillance**: Implement in surveillance systems to trigger alerts based on ambient light conditions, improving monitoring effectiveness.
