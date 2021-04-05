/*
   modified 2 April 2021
   by Chris Swagler
   purpose: to use the whisker sensor (RedBot Bumper) to detect if the whisker is bumped

   Note: the bumper is bumped when the whisker touches the metal on the opposite
         side that the whisker protrudes from
*/

#include <RedBot.h>

int bumperPin = 3;
RedBotBumper bumper = RedBotBumper(bumperPin);  // initialzes bumper object on pin 3

int bumperState;  // state variable to store the bumper value

void setup() {
  Serial.begin(9600);
}

void loop() {
  bumperState = bumper.read();  // default INPUT state is HIGH, it is LOW when bumped

  if (bumperState == LOW) {
    Serial.println("bumped!");
  }

}
