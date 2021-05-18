/*
   Modified 18 May 2021
   by Chris Swagler
   purpose: to use the DSD TECH HM-10 Bluetooth module to communicate between the serial monitor
            and an external device, specifically a phone using an app. By sending "On" or "Off" from
            the app, this sketch controls the on-board LED

   Note: This sketch ~should~ work with both Andriod and Apple phones. I personally can only attest
         to the Apple version working since, well, that's the only phone I have.

         The app is called "DSD TECH Bluetooth" and is free in the App Store and Google Play.

   Configuration steps:
      - download the DSD TECH Bluetooth app
      - wire the module according to the wiring diagram
      - use the app to select the device, should be called "DSD TECH" as one of the available devices
      - if it doesn't appear, double check your wiring for the bluetooth module
      - after the module is connected, you can use the text box in the app to send to the serial monitor here
        or you can send messages in the serial monitor to be received on the app
*/

#include <SoftwareSerial.h>
SoftwareSerial EEBlue(10, 11); // RX | TX

void setup() {
  Serial.begin(9600);
  EEBlue.begin(9600);  //Default Baud should work for this module
  Serial.println("The bluetooth gates are open. Connect to the device!");
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  // Feed all data from Serial monitor to bluetooth
  if (Serial.available()) {
    EEBlue.write(Serial.read());
  }

  // Feed any data from bluetooth to Serial monitor.
  if (EEBlue.available()) {
    //can either use .read() or .readString() to process the message

    //CHARACTER APPROACH - MUCH FASTER, USEFUL FOR QUICK INPUT/OUTPUT DECISIONS
    //                   - disadvantage: can only process single characters, not good for messages
    /*
      //the message will arrive character by character
      char appData = EEBlue.read();
      Serial.write(appData);

      if (appData == '0') {
      digitalWrite(LED_BUILTIN, LOW);
      }
      else if (appData == '1') {
      digitalWrite(LED_BUILTIN, HIGH);
      }
    */

    //STRING APPROACH - SIGNIFICANTLY SLOWER, PROCESSES FULL STRING
    //                - disadvantage: takes a second or two to process, not good for immediate controls
    String appData = EEBlue.readString();
    Serial.print(appData);

    if (appData == "Off") {
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if (appData == "On") {
      digitalWrite(LED_BUILTIN, HIGH);
    }
  }

}
