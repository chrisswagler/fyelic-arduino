/*
  modified 29 Nov 2020
  by Chris Swagler
  purpose: blink an LED on and off with 1 second delays
  wire diagram : 
     - Note : the LED is polarized! The longer end should be connected to the pin
              and the shorter end should be connected to ground. Also, the resistor 
              used is 330 ohm
*/

int LEDpin = 13;

void setup() {
  pinMode(LEDpin, OUTPUT);      // Set pin 13 to output
}


void loop() {

  digitalWrite(LEDpin, HIGH);   // Turn on the LED
  delay(1000);              // Wait for one second

  digitalWrite(LEDpin, LOW);    // Turn off the LED\
  delay(1000);              // Wait for one second

}
