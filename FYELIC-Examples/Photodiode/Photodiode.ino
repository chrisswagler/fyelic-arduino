/*
   modified 2 April 2021
   by Chris Swagler
   purpose: to use a photodiode to measure the amount of light sensed

   Note: with this configuration, lower sensorValue corresponds to higher light
         wheras higher sensorValue corresponds to lower light
         Also, the photodiode is polarized! Like an LED, the longer side is the 
         anode (+) and shorter is cathode (-)
*/

int sensorPin = A0;
int sensorValue;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
}
