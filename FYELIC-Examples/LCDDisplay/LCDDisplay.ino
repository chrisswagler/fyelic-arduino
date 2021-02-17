/*
  modified 29 Nov 2020
  by Chris Swagler
  purpose: to display two simple messages on the LCD display
*/

/*
   Note: double check your wiring if the display isn't working - lots of wires leave lots of room for error
   Also you might need to change the contrast_level constant depending on your specific display!
   If you choose to use a different digital pin for the contrast level, make sure it has a "~" like pin 6 has
*/

#include <LiquidCrystal.h>          //the liquid crystal library contains commands for printing to the display

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);   // tell the RedBoard what pins are connected to the display

int contrast_level = 90; //this value might need to be changed depending on your LCD


void setup() {

  //these two lines are used to set the contrast level for the LCD
  pinMode(6, OUTPUT);
  analogWrite(6, contrast_level);
  lcd.begin(16, 2);                 //tell the lcd library that we are using a display that is 16 characters wide and 2 characters high
  lcd.clear();                      //clear the display
}

void loop() {
  lcd.setCursor(0, 0);              //set the cursor to the 0,0 position (top left corner)
  lcd.print("Hello, world!");       //print hello, world! starting at that position

  lcd.setCursor(5, 1);              //move the cursor to the sixth space of the bottom row
  lcd.print("FYELIC");             //print FYELIC
}
