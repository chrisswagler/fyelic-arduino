/*
   modified 26 March 2021
   by Chris Swagler
   purpose: to use the IR emitter to send out different hexadecimal codes
   
   Note: THE IRREMOTE LIBRARY AT THE TIME OF THIS SKETCH WAS IN THE PROCESS OF BEING UPDATED.
         Accordingly, this sketch might not work for the most recent version of the libary.
         Check the github page for the IRremote https://github.com/Arduino-IRremote/Arduino-IRremote
         to find the latest version and any updates necessary to your code.

         For this sketch, the most recent version of the library was not functional and had bugs,
         so the version used for this was Version 2.2.3. To get this version, go to
         Tools > Manage Libraries > search IRremote > change the version and install library

         To test if this is working, an IR receiver should be used with the emitter. I personally connected
         another redboard and uploaded the IR_Receiver sketch (found in the FYELIC library) to test
         that it was actually receiving these signals. 
*/

//An IR LED must be connected to Arduino PWM pin 3.

#include <IRremote.h>
IRsend irsend;
void setup() {}

void loop() {
  irsend.sendRC5(0x0, 8); //send 0x0 code (8 bits)
  delay(200);
  irsend.sendRC5(0x1, 8); //send 0x1 code (8 bits)
  delay(200);
  irsend.sendRC5(0xFF, 8); //send 0xFF code (8 bits)
  delay(200);
  irsend.sendRC5(0x5F, 8); //send 0x5F code (8 bits)
  delay(200);
}
