/******************************************
  Website: www.elegoo.com

  Time:2017.12.12

 ******************************************/
/*
   modified 24 March 2021
   by Chris Swagler
   purpose: to use the 7 color flash LED module and demonstrate the LED circuit
*/

void setup() {
  // initialize  the digital  pin  as an output.
  pinMode(13, OUTPUT);
}

void loop()  {
  digitalWrite(13,  HIGH);  // set  the LED on
  //note that just turning the pin to HIGH runs the sequence for this module
  //turning the pin to low and back to high will reset the sequence from the start
}
