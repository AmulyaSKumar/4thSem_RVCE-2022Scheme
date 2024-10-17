# DHT11 Sensor Experiment on Raspberry Pi

## Components Required
- Raspberry Pi 4 Model
- DHT11 Temperature and Humidity Sensor
- Breadboard
- Jumper Wires

## Purpose
To measure and display the temperature and humidity levels in the environment using the DHT11 sensor and Raspberry Pi.

## Connection
1. Connect the DHT11 sensor as follows:
   - VCC (Power) pin to 3.3V on the Raspberry Pi.
   - GND (Ground) pin to any GND pin on the Raspberry Pi.
   - DATA pin to GPIO pin (for example, GPIO4).
   - If necessary, connect a resistor between the VCC and DATA pins.

## Installation Instructions
### 1. Update and Upgrade Packages
Open the terminal and run the following command:
```bash
sudo apt update && sudo apt upgrade
```
### 2. Create a New Directory for the Project
```bash
mkdir dht_test
```
### 3.Enter into that Directory
```bash 
cd dht_test
```
### 4.Create a virtual Environment 
```bash
python3 -m env venv
```
### 5.Activate the virtual environment
```bash
source venv/bin/activate
```
### 6.Install 
```bash
python3 -m pip install adafruit-circuitpython-dht
```
### 7.Save your Python program in the same folder (dht_test) where the virtual environment is created and run it 
```bash
python3 file.py
```
## Code
```python
import time
import board
import adafruit_dht

# Initialize the sensor
sensor = adafruit_dht.DHT11(board.D4, use_pulseio=False)

while True:
    try:
        temperature_c = sensor.temperature
        temperature_f = temperature_c * (9 / 5) + 32
        humidity = sensor.humidity

        print(f"Temp={temperature_c:0.1f}C, Temp={temperature_f:0.1f}F, Humidity={humidity:0.1f}%")

    except Exception as error:
        print(f"Unhandled exception: {error}")
        sensor.exit()
        break  # Exit the loop if there's a critical error

    time.sleep(1)
```

## Code with Cloud
```python
import time
import board
import adafruit_dht
import thingspeak
from rpi_lcd import LCD

# Define your ThingSpeak channel parameters
channel_id = 
write_key = ''       
# Initialize the ThingSpeak channel
channel = thingspeak.Channel(id=channel_id, api_key=write_key)

# Initialize the LCD
lcd = LCD()

# Initialize the sensor (DHT11 connected to GPIO 4)
sensor = adafruit_dht.DHT11(board.D4, use_pulseio=False)


while True:
    try:
        # Read the sensor data
        temperature_c = sensor.temperature
        temperature_f = temperature_c * (9 / 5) + 32
        humidity = sensor.humidity

        # Print the values to the serial port
        print("Temp={0:0.1f}C, Temp={1:0.1f}F, Humidity={2:0.1f}%".format(temperature_c, temperature_f, humidity))

        # Display the values on the LCD
        lcd.text("Temp={0}C".format(temperature_c), 1)
        lcd.text("Humi={0}%".format(humidity), 2)

        # Send the data to ThingSpeak
        response = channel.update({'field1': temperature_c, 'field2': humidity})
        print("Data sent to ThingSpeak. Response:", response)
        
    except Exception as error:
        sensor.exit()
        raise error

    # Wait before taking the next reading
    time.sleep(15)
```

### Applications
- **Weather Monitoring:** Used in home weather stations to track local weather conditions.
- **Greenhouse Monitoring:** Helps in maintaining optimal conditions for plant growth.
- **HVAC Systems:** Used for controlling heating, ventilation, and air conditioning systems based on temperature and humidity levels.
- **Data Logging:** Collecting environmental data for research or analysis.

