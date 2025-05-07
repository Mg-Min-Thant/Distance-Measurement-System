# Distance Measurement System Using Arduino

This project uses an Arduino, HC-SR04 ultrasonic sensor, I2C 16x2 LCD, and an LED to measure the distance to an object and provide a visual alert based on a distance threshold.

## Features

- Measures distance using ultrasonic sensor
- Displays distance on an I2C LCD screen
- Turns LED ON or OFF depending on distance (threshold: 30 cm)
- Sends distance data to Serial Monitor

## Components

- Arduino Uno or Nano
- HC-SR04 ultrasonic sensor
- 16x2 I2C LCD display
- LED + 220Ω resistor
- Breadboard and jumper wires

## Connections

**Ultrasonic Sensor:**
- VCC → 5V  
- GND → GND  
- TRIG → D13  
- ECHO → D12  

**LCD (I2C):**
- SDA → A4  
- SCL → A5  

**LED:**
- Anode → D7 (via 220Ω resistor)  
- Cathode → GND  

## How It Works

1. The sensor sends an ultrasonic pulse and waits for the echo.
2. The Arduino calculates the distance using the time difference.
3. The distance is shown on the LCD.
4. If the distance is ≤ 30 cm, the LED turns **OFF**.
5. If the distance is > 30 cm, the LED turns **ON**.

## Requirements

- Arduino IDE  
- LiquidCrystal_I2C library (install via Library Manager)

## License

This project is open-source and free to use.

