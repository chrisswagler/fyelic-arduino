/*
   modified 2 Dec 2020
   by Chris Swagler
   purpose: to communicate between two Arduino boards, blinking the second
            Arduino's pin 13 LED
            This secondaryArduino code receives the numbers 0-5 from Arduino 1,
            and blinks the LED on/off when it receives numbers 0 and 3
   adapted from: https://www.instructables.com/I2C-between-Arduinos/
*/


/*
   Note: this code is for Arduino 2, which receives FROM the other Arduino
         Also, double check the Serial monitor to see if this board is receiving properly
*/


// Include the required Wire library for I2C
#include <Wire.h>
int LED = 13;
int x = 0;
void setup() {
  Serial.begin(9600);
  // Define the LED pin as Output
  pinMode (LED, OUTPUT);
  // Start the I2C Bus as Slave on address 9 (Arduino 2)
  Wire.begin(9);
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
}
void loop() {
  //If value received is 0 turn the LED on
  if (x == 0) {
    digitalWrite(LED, HIGH);
  }
  //If value received is 3 turn the LED off
  else if (x == 3) {
    digitalWrite(LED, LOW);
  }
}

void receiveEvent() {
  x = Wire.read();    // read one character from the I2C
  Serial.println(x);  //print the character to Serial monitor
}
