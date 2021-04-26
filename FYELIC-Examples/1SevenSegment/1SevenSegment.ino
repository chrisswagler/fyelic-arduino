/*
   modified 2 April 2021
   by Chris Swagler
   purpose: to use a single digit 7-segment display to increment through
            the digits 0-9 every second

   Additional resources: https://www.circuitbasics.com/arduino-7-segment-display-tutorial/
*/
#include "SevSeg.h"
SevSeg sevseg;

void setup() {
  byte numDigits = 1; //only a single digit seven segment in this sketch
  byte digitPins[] = {};
  byte segmentPins[] = {6, 5, 2, 3, 4, 7, 8, 9};
  bool resistorsOnSegments = true;

  byte hardwareConfig = COMMON_CATHODE;
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
}

void loop() {
  for (int i = 0; i < 10; i++) {
    sevseg.setNumber(i); //set the number to be the index of the for loop
    sevseg.refreshDisplay();
    delay(1000);
  }
}
