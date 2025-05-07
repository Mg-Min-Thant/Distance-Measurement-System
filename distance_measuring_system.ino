#include <LiquidCrystal_I2C.h>  // Include the I2C LCD library

// Define pins for ultrasonic sensor
int trig = 13;
int echo = 12;

// Variables to store duration and distance
long duration;
float distance;

// Define LED pin
int led = 7;

// Initialize the LCD at I2C address 0x27 with 16 columns and 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup () {
  pinMode(trig, OUTPUT);   // Set trigger pin as output
  pinMode(echo, INPUT);    // Set echo pin as input
  pinMode(led, OUTPUT);    // Set LED pin as output
  Serial.begin(9600);      // Start serial communication at 9600 baud
  lcd.init();              // Initialize the LCD
  lcd.backlight();         // Turn on the LCD backlight
}

// Function to measure distance using ultrasonic sensor
void ultrasonic () {
  digitalWrite(trig, HIGH);         // Send a 10 microsecond pulse
  delayMicroseconds(10);           
  digitalWrite(trig, LOW);         
  duration = pulseIn(echo, HIGH);   // Measure how long the echo takes to return
  distance = duration * 0.034 / 2;  // Convert time into distance in cm
}

void loop() {
  ultrasonic();  // Call function to update distance

  // If object is closer than or equal to 30 cm
  if (distance <= 30) { 
    digitalWrite(led, LOW);  // Turn OFF LED

    // Display distacne on LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Distance=");
    lcd.print(distance);
    lcd.print("cm");
    lcd.setCursor(3, 1);
    lcd.print("LED is OFF!");

    // Print distance to serial
    Serial.print("Distance is ");
    Serial.print(distance);
    Serial.print("cm.");
    Serial.println("LED is OFF!");
    delay(1000);  // Wait for 1 second
  }
  
  // If object is farther than 30 cm
  else { 
    digitalWrite(led, HIGH);  // Turn ON LED

    // Display distacne on LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Distance is over");
    lcd.setCursor(3, 1);
    lcd.print("LED is ON!");

    // Print distance to serial
    Serial.print("Distance is out of range. Distance is ");
    Serial.print(distance);
    Serial.print("cm.");
    Serial.println("LED is ON!");
    delay(1000);  // Wait for 1 second
  }
}

