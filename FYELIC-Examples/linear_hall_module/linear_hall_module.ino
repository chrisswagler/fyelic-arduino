/*
   modified 24 March 2021
   by Chris Swagler
   purpose: to use the linear magnetic hall sensor to illuminate the LED
            when a magnetic field is present

   Note: the potentiometer on the module can be used to adjust the
         sensitivity
*/

int Led = 13; // define LED Interface
int SENSOR = 10; // define the Hall magnetic sensor interface
int val; // define numeric variables val
void setup() {
  pinMode (Led, OUTPUT) ;  // define LED as output interface
  pinMode (SENSOR, INPUT) ; // define the Hall magnetic sensor line  as input
}
void loop() {
  val = digitalRead (SENSOR) ; // read sensor line
  if (val == LOW) // when the Hall sensor detects a magnetic field, ArduinoLED lights up
  {
    digitalWrite (Led, LOW);
  }
  else {
    digitalWrite (Led, HIGH);
  }
}
