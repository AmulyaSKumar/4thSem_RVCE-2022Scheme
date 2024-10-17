# Arduino LED Control Experiment

## Aim:
To control three LEDs by turning them on and off sequentially with different time delays using an Arduino board.

## Components Required:
- 1 x Arduino Uno
- 3 x LEDs
- Jumper wires
- Breadboard

## Purpose of the Experiment:
The experiment demonstrates how to control multiple LEDs using digital pins on the Arduino and implement time-based sequential lighting using delay functions. This helps in understanding the basic concepts of output control in microcontroller-based systems.

 ##  Connections:
   - Connect the longer leg (anode) of LED 1 to digital pin 11 on the Arduino.
   - Connect the longer leg (anode) of LED 2 to digital pin 12 on the Arduino.
   - Connect the longer leg (anode) of LED 3 to digital pin 13 on the Arduino.
   - Connect the shorter leg (cathode) of all LEDs to the GND pin on the Arduino.

## Code:
```cpp
// Define LED pins
const int led1 = 11;
const int led2 = 12;
const int led3 = 13;

void setup() {
    // Initialize LED pins as output
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
}

void loop() {
    // Turn on LED 1 for 1 second
    digitalWrite(led1, HIGH);
    delay(1000); // 1000 milliseconds = 1 second
    digitalWrite(led1, LOW);
    
    // Turn on LED 2 for 2 seconds
    digitalWrite(led2, HIGH);
    delay(2000); // 2000 milliseconds = 2 seconds
    digitalWrite(led2, LOW);
    
    // Turn on LED 3 for 3 seconds
    digitalWrite(led3, HIGH);
    delay(3000); // 3000 milliseconds = 3 seconds
    digitalWrite(led3, LOW);
}
```
 
##  Output:
   - LED 1 will turn on for 1 second, then turn off.
   - LED 2 will turn on for 2 seconds, then turn off.
   - LED 3 will turn on for 3 seconds, then turn off.
   - The sequence will repeat continuously.

 ## Applications:
- Sequential LED lighting for visual effects.
- Simulation of traffic light systems.
- Projects requiring basic control of multiple outputs with timing functionality
