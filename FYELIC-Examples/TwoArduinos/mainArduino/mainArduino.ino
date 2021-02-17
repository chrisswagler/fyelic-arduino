/*
   modified 2 Dec 2020
   by Chris Swagler
   purpose: to communicate between two Arduino boards, blinking the second
            Arduino's pin 13 LED
            This mainArduino code sends numbers 0-5 to Arduino 2, which processes
            these numbers
   adapted from: https://www.instructables.com/I2C-between-Arduinos/
*/


/*
   Note: this code is for Arduino 1, which transmits TO the other Arduino
*/


// Include the required Wire library for I2C
#include <Wire.h>
int x = 0;
void setup() {
  // Start the I2C Bus as Master (Arduino 1)
  Wire.begin();
}
void loop() {
  Wire.beginTransmission(9); // transmit to device #9 (Arduino 2)
  Wire.write(x);              // sends x
  Wire.endTransmission();    // stop transmitting
  x++; // Increment x
  if (x > 5) {
    x = 0; // `reset x once it gets 6
  }
  delay(500);
}
