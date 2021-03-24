/*
   modified 24 March 2021
   by Chris Swagler
   purpose: to use the line tracking module to detect a change in color

   Note: this is the same type of sensor as the IRsensor sketch. It can be adjusted
         with the potentiometer based on the sensitivity
*/

int Led = 13; //define LED port
int buttonpin = 3; //define switch port
int val;//define digital variable val
void setup() {
  pinMode(Led, OUTPUT); //define LED as a output port
  pinMode(buttonpin, INPUT); //define switch as a output port
}
void loop() {
  val = digitalRead(buttonpin); //read the value of the digital interface 3 assigned to val
  if (val == HIGH) //when the switch sensor have signal, LED blink
  {
    digitalWrite(Led, HIGH);
  }
  else {
    digitalWrite(Led, LOW);
  }
}
