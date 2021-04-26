/*
   modified 2 April 2021
   by Chris Swagler
   purpose: to use the 4-digit 7-segment display to display a single number

   Additional resources: https://www.circuitbasics.com/arduino-7-segment-display-tutorial/
*/

#include "SevSeg.h"
SevSeg sevseg;

void setup() {
  byte numDigits = 4; //for a 4 digit display
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};

  bool resistorsOnSegments = true;
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_CATHODE;
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
}

void loop() {
  //setNumber(x, y) will display the number x (maximum 4 digits)
  //with decimal point at y places from the right (y is 0, 1, 2, or 3)
  
  sevseg.setNumber(4769, 3); //displays the number 4.769
  sevseg.refreshDisplay();
}
