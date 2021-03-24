/*
   modified 24 March 2021
   by Chris Swagler
   purpose: to use the laser emit module as a blinking LED
*/

int laserPin = 13;
void setup() {
  pinMode (laserPin, OUTPUT);
}

void loop() {
  digitalWrite (laserPin, HIGH); // open the laser head
  delay (1000); // delay one second
  digitalWrite (laserPin, LOW); // turn off the laser head
  delay (1000); // delay one second
}
