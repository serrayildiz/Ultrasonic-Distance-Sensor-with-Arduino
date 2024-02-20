# Ultrasonic Distance Sensor with Arduino

This project utilizes an Arduino microcontroller along with an ultrasonic distance sensor to measure distances and provide warnings when objects are detected within certain ranges. The distance measurements are displayed on an LCD screen and communicated via Bluetooth serial communication. Additionally, a buzzer is used to provide audible alerts when objects are detected within close proximity.

## Components

- Arduino Uno
- HC-SR04 Ultrasonic Distance Sensor
- LCD Display (I2C)
- Buzzer
- Bluetooth Module (HC-05)
- Jumper Wires

## Installation

1. Connect the HC-SR04 sensor to the Arduino as follows:
   - VCC pin to Arduino 5V
   - GND pin to Arduino GND
   - Trig pin to Arduino digital pin 7
   - Echo pin to Arduino digital pin 6
2. Connect the buzzer to the Arduino:
   - Positive (longer leg) to Arduino digital pin 8
   - Negative (shorter leg) to Arduino GND
3. Connect the LCD display to the Arduino via I2C:
   - SDA pin to Arduino A4
   - SCL pin to Arduino A5
   - VCC pin to Arduino 5V
   - GND pin to Arduino GND
4. Connect the Bluetooth module to the Arduino:
   - RX pin to Arduino digital pin 11 (TX)
   - TX pin to Arduino digital pin 10 (RX)
   - VCC pin to Arduino 5V
   - GND pin to Arduino GND
5. Upload the provided sketch to the Arduino board.

## Usage

1. Power up the Arduino board.
2. Ensure that the Bluetooth module is paired with your device.
3. Open a serial monitor or a Bluetooth terminal on your device to receive distance measurements and warnings.
4. The LCD display will show distance measurements in centimeters.
5. Depending on the measured distance:
   - If distance is greater than 200cm, no warning is given.
   - If distance is between 200cm and 100cm, a "Please keep away" message is displayed.
   - If distance is between 100cm and 50cm, a "Keep away" message is displayed, and the buzzer emits short beeps.
   - If distance is less than or equal to 50cm, a "STAY AWAY!" message is displayed, and the buzzer emits longer beeps.

## Contributions

Contributions to improve the project are welcome. Feel free to fork the repository, make your changes, and submit a pull request.

