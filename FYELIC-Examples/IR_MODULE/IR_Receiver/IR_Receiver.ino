/*
   modified 26 March 2021
   by Chris Swagler
   purpose: to use the IR receiver to receive signals and output their hexadecimal value

   Note: THE IRREMOTE LIBRARY AT THE TIME OF THIS SKETCH WAS IN THE PROCESS OF BEING UPDATED.
         Accordingly, this sketch will not work for the most recent version of the libary.
         Check the github page for the IRremote https://github.com/Arduino-IRremote/Arduino-IRremote
         to find the latest version and any updates necessary to your code.

         For this sketch, the most recent version of the library was not functional and had bugs,
         so the version used for this was Version 2.2.3. To get this version, go to
         Tools > Manage Libraries > search IRremote > change the version and install library

         Functional edits for your version - Use the serial monitor to determine the value of the
         incoming IR signal in hexadecimal format. You can then use if statements to respond to 
         particular signals using _results.value_. They aren't included here since there are a wide
         variety of remotes/ IR emitters.
*/
#include <IRremote.h>
int RECV_PIN = 11;       //Infrared signal receiving pin
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  
  //if the recevier receives a signal, decode the results
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX); //print the results in hexadecimal format
    irrecv.resume();        // prepare to receive the next value
  }
}
