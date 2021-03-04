/*
   modified 4 March 2021
   by Chris Swagler
   purpose: display to the serial monitor the key pressed on the hexaKey keypad
   https://www.circuitbasics.com/how-to-set-up-a-keypad-on-an-arduino/
*/

/*
  Note: there are a wide variety of keypad configurations, so check the hexaKeys array
  and also the link above to see if your keypad is compatible
  Also, make sure to download the Adafruit Keypad library for this code to work!
*/

#include <Adafruit_Keypad.h>
#include <Keypad.h>

//rows and cols for a 4x4 keypad
const byte ROWS = 4;
const byte COLS = 4;

//keypad configuration (can be changed based on your specific keypad)
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'0', 'F', 'E', 'D'}
};

//pins to connect to the board
//this pin configuration worked for the keypads supplied at FYELIC,
//if your rows/cols are inverted, simply change the pin numbers accordingly
byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {9, 8, 7, 6};

//create an instance of a Keypad using the above configuration
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  //obtains the key from the keypay
  char customKey = customKeypad.getKey();

  //if there was a key pressed, print the key to the serial monitor
  if (customKey) {
    Serial.println(customKey);
  }
}
