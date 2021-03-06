/*
   modified 24 March 2021
   by Chris Swagler
   purpose: to use the tilt switch / ball switch sensor to turn on an LED

   Note: if you shake the sensor, you can hear the ball shaking inside it.
         Holding the sensor in an upright orientation will turn the LED off
*/

int Led = 13; //define LED port
int buttonpin = 3; //define switch port
int  val;//define digital variable val
void setup() {
  Serial.begin(9600);
  pinMode(Led, OUTPUT); //define LED as a output port
  pinMode(buttonpin, INPUT); //define switch as a output port
  digitalWrite(buttonpin, LOW);
}

void loop() {
  val = digitalRead(buttonpin); //read the value of the digital interface 3 assigned to val
  if (val == HIGH) //when the switch sensor have signal, LED blink
  {
    digitalWrite(Led, HIGH);
    Serial.println("HIGH!");
  }
  else {
    digitalWrite(Led, LOW);
    Serial.println("LOW!");
  }
}
