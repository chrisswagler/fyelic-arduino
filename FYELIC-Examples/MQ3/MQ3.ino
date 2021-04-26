/*
   modified 26 April 2021
   by Chris Swagler
   purpose: to use the MQ3 (alcohol sensor) to display the sensor reading to the serial monitor

   Note: the MQ3 sensors at FYELIC have the breakout board already connected to them, which reduces
         the number of pins from 6 (on the MQ3 itself) to 4. This is how the 4 should be wired:
         GND - GND
         B1 - load resistance of 10k to GND, and also A0
         H1 - 5V
         A1 - 5V
*/

int MQ3 = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(MQ3); //higher sensor value -> higher alcohol presence
  Serial.println(sensorValue, DEC);
  delay(100);
}
