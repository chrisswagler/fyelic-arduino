/******************************************
  Website: www.elegoo.com

  Time:2017.12.12

 ******************************************/
/*
   modified 24 March 2021
   by Chris Swagler
   purpose: to use the dual color LED to transition from red to green and back
*/

int  redpin =  11;     // select the pin for  the red LED
int  yellowpin  = 10;      // select the pin  for  the blueLED
int  val;

void setup()
{
  pinMode(redpin, OUTPUT);
  pinMode(yellowpin, OUTPUT);
}

void loop() {
  for (val = 255; val > 0; val--) {
    analogWrite(redpin, val);
    analogWrite(yellowpin, 255 - val);
    delay(15);
  }

  for (val = 0; val < 255;  val++) {
    analogWrite(redpin, val);
    analogWrite(yellowpin, 255 - val);
    delay(15);
  }
}
