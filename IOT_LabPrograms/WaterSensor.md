# Water Sensing and Email Notification System using Raspberry Pi

## Aim
To detect the presence of water using a water sensor and send an email notification when water is detected.

## Components Required
- Raspberry Pi (any model with GPIO support)
- Water sensor
- Buzzer
- Jumper wires
- Breadboard (optional)
- Internet connection (for sending emails)
  
## Connection
1. **Water Sensor**:
   - Connect the VCC pin of the water sensor to the 3.3V pin on the Raspberry Pi.
   - Connect the GND pin of the water sensor to a GND pin on the Raspberry Pi.
   - Connect the output pin of the water sensor to GPIO pin 4 (WPIN) on the Raspberry Pi.

2. **Buzzer**:
   - Connect the positive (longer) pin of the buzzer to GPIO pin 17 (BUZZERPIN) on the Raspberry Pi.
   - Connect the negative (shorter) pin of the buzzer to a GND pin on the Raspberry Pi.

# Instructions for Setting Up an App Password in Gmail

1. **Navigate to Google Account Settings**:
   - In your Gmail inbox, click on **Manage your Google Account** (located next to the Sign Out button).

2. **Activate 2-Step Verification**:
   - Go to the **Security** section.
   - Enable **2-Step Verification**.

3. **Create an App Password**:
   - Once 2-Step Verification is enabled, look for the **App Passwords** option.
   - Enter a name for the application (you can choose any name) and click **Create**.
   - A unique app password will be generated, appearing as `aaaa aaaa aaaa aaaa`.

4. **Store the App Password**:
   - Copy the generated app password and save it in a secure text file.
   - In your code, use this app password without any spaces.

5. **Configure the Recipient's Email**:
   - You can specify any Gmail address as the recipient (preferably one with 2-Step Verification disabled).

## Code
```python
import RPi.GPIO as GPIO
import smtplib
from email.mime.text import MIMEText
import time

# Email settings
EMAIL_ADDRESS = 'xyz@gmail.com'  # Your email address
EMAIL_PASSWORD = ' '   # Your email password
TO_EMAIL = ''    # Recipient's email address

# Set up GPIO
WPIN = 4  
BUZZERPIN = 17
GPIO.setmode(GPIO.BCM)
GPIO.setup(WPIN, GPIO.IN)
GPIO.setup(BUZZERPIN, GPIO.OUT)

# Function to send email notification
def send_email():
    msg = MIMEText('Water sensor detected water!')
    msg['Subject'] = 'Alert: Water sensor is wet!'
    msg['From'] = EMAIL_ADDRESS
    msg['To'] = TO_EMAIL

    try:
        with smtplib.SMTP_SSL('smtp.gmail.com', 465) as server:
            server.login(EMAIL_ADDRESS, EMAIL_PASSWORD)
            server.send_message(msg)
            print("Email sent successfully")
    except Exception as e:
        print(f"Failed to send email: {e}")

# Main loop
try:
    print("Water Sensor with email (CTRL+C to exit)")
    time.sleep(2)  
    print("Ready")

    while True:
        if GPIO.input(WPIN):  # If water is detected
            print("Water sensor is wet!")
            GPIO.output(BUZZERPIN, True)
            send_email()
            time.sleep(5)  # Delay to avoid multiple detections
            GPIO.output(BUZZERPIN, False)

except KeyboardInterrupt:
    print("Program terminated")
finally:
    GPIO.cleanup()  # Clean up GPIO on exit
```

## Output
- When water is detected, the buzzer sounds an alert, and an email notification is sent to the specified recipient.

## Applications
- **Home Safety**: Detecting water leaks in homes to prevent damage.
- **Industrial Applications**: Monitoring water levels in tanks or detecting leaks in factories.
- **Agricultural Use**: Checking for excess water in irrigation systems.
