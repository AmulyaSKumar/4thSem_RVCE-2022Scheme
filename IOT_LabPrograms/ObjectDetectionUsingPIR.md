# Object Detection using PIR Sensor and LED Interfacing with Raspberry Pi

## Objective
To detect motion using a PIR sensor and indicate detection with an LED.

## Components Required
- Raspberry Pi
- PIR Sensor
- LED
- Jumper Wires
- Breadboard (optional)

## Methodology
1. Connect the PIR sensor output pin to GPIO pin 12 on the Raspberry Pi.
2. Connect the LED positive (anode) pin to GPIO pin 11 and the negative (cathode) pin to GND.
3. Power up the Raspberry Pi and ensure you have the necessary libraries installed (`RPi.GPIO`).

## Code (Without Cloud Integration)

```python
import time
import RPi.GPIO as GPIO

# Set GPIO pin numbers
pir_pin = 12  # PIR sensor output pin
led_pin = 11   # LED pin

# Setup GPIO
GPIO.setmode(GPIO.BOARD)
GPIO.setup(pir_pin, GPIO.IN)
GPIO.setup(led_pin, GPIO.OUT)

try:
    print("PIR Sensor Test (CTRL+C to exit)")
    time.sleep(2)  # Warmup time for PIR sensor
    print("Ready")
   
    while True:
        if GPIO.input(pir_pin):  # If motion is detected
            print("Motion detected!")
            GPIO.output(led_pin, GPIO.HIGH)  # Turn on LED
            time.sleep(2)
            GPIO.output(led_pin, GPIO.LOW)
        else:
            print("No motion detected")
        time.sleep(1)
except KeyboardInterrupt:
    print("Exiting...")
finally:
    GPIO.cleanup()
```
## Code(With Cloud)

```python
import http.client     # For HTTP client
import urllib.parse    # For parsing URL strings
import time
import RPi.GPIO as GPIO

# Setup GPIO pins
GPIO.setmode(GPIO.BOARD)
GPIO.setup(7, GPIO.IN)  # PIR sensor input
GPIO.setup(18, GPIO.OUT)  # LED pin
GPIO.setwarnings(False)

# Put your API Key here
key = "76I4VO9R18ABOURD"  

def PIR():
    while True:
        if GPIO.input(7):  # If motion is detected
            GPIO.output(18, True)  # Turn on LED
            print("Object detected")
            time.sleep(5)  # LED stays on for 5 seconds
        else:
            GPIO.output(18, False)  # Turn off LED
            print("No detection")
            time.sleep(5)

        # Send data to ThingSpeak
        Intrusion = GPIO.input(7)
        params = urllib.parse.urlencode({'field1': Intrusion, 'key': key})
        headers = {"Content-type": "application/x-www-form-urlencoded", "Accept": "text/plain"}
        
        # Connect to ThingSpeak
        conn = http.client.HTTPConnection("api.thingspeak.com:80")
        try:
            conn.request("POST", "/update", params, headers)
            response = conn.getresponse()
            print(Intrusion)
            print(response.status, response.reason)
            data = response.read()
            conn.close()
        except:
            print("Connection failed")
        break

if __name__ == "__main__":
    while True:
        PIR()
```
## Output
- When motion is detected, the LED turns on, and the message **"Object detected"** is printed.
- If no motion is detected, the LED turns off, and the message **"No detection"** is printed.
- The PIR sensor's status is sent to ThingSpeak.

## ThingSpeak Configuration
To configure ThingSpeak for receiving data from your PIR sensor, follow these steps:

### Create a ThingSpeak Account
- Go to [ThingSpeak](https://thingspeak.com/) and sign up for a free account.

### Create a New Channel
1. After logging in, click on the **"Channels"** tab.
2. Click on **"New Channel"**.
3. Give your channel a name (e.g., **"PIR Sensor Data"**).
4. In the **"Field 1"** input box, enter a name (e.g., **"Intrusion Status"**).
5. Click on **"Save Channel"**.

### Get Your API Key
- After creating the channel, you will be redirected to the channel view.
- Copy the **"Write API Key"** shown on this page. Replace the existing API key in your code with this key.

### Check Your Data
- Go to the **"Data"** tab in your channel to view the incoming data.
- You can create visualizations to monitor the PIR sensor's activity over time.

## Applications
- Home security systems to detect intrusions.
- Automated lighting systems that respond to movement.
- Smart surveillance systems for monitoring.
