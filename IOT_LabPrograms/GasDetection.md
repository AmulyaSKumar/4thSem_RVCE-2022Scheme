# USB-Powered Gas Detector with LED Display Using Arduino

## Components Required
- **Arduino Uno** (or any compatible board)
- **Gas Sensor Module** (e.g., MQ-2 or MQ-7)
- **LED** (Any color)
- **220Ω Resistor** (for LED)
- **Breadboard** (optional, for easy connections)
- **Jumper Wires**
- **USB Power Supply**

## Purpose
To develop a gas detector that can sense the presence of gas (e.g., LPG, methane) and indicate it using an LED. The readings are also printed to the serial monitor for monitoring purposes.

## Circuit Connections
- Connect the **A0** pin of the gas sensor to **Analog Pin A0** on the Arduino (gasPin).
- Connect the **VCC** pin of the gas sensor to **5V** on the Arduino.
- Connect the **GND** pin of the gas sensor to **GND** on the Arduino.
- Connect the **anode (long leg)** of the LED to **Digital Pin 13** on the Arduino (ledPin).
- Connect the **cathode (short leg)** of the LED to a **220Ω resistor**, and then connect the other end of the resistor to **GND** on the Arduino.

## Code
```cpp
const int gasPin = A0; // Pin connected to the gas sensor
const int ledPin = 13; // Pin connected to the LED

void setup() {
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  pinMode(gasPin, INPUT); // Set gas sensor pin as input
  Serial.begin(9600); // Initialize serial communication at 9600 bps
}

void loop() {
  int gasValue = analogRead(gasPin); // Read the gas sensor value
  float voltage = gasValue * (5.0 / 1023.0); // Convert to voltage

  Serial.print("Gas Value: "); // Print gas value to serial monitor
  Serial.print(gasValue);
  Serial.print("\tVoltage: "); // Print voltage to serial monitor
  Serial.println(voltage, 3); // Print voltage with 3 decimal places

  if (voltage > 1.5) { // If voltage exceeds 1.5V
    digitalWrite(ledPin, HIGH); // Turn LED ON
    Serial.print("LED ON\n"); // Print LED status to serial monitor
  } else {
    digitalWrite(ledPin, LOW); // Turn LED OFF
    Serial.print("LED OFF\n"); // Print LED status to serial monitor
  }

  delay(1000); // Wait for 1 second before the next loop iteration
}
```

## Output
- When the gas concentration exceeds the threshold, the LED lights up, indicating the presence of gas.
- The serial monitor displays the gas value and voltage readings every second.

## Applications
- **Home Safety**: Detecting harmful gases in residential areas.
- **Industrial Safety**: Monitoring gas leaks in factories and workplaces.
- **Research Projects**: Conducting experiments related to gas detection and safety measures.

