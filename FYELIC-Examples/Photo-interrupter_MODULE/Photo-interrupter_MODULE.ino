/*
 * modified 24 March 2021
 * by Chris Swagler
 * purpose: to use the photo-interrupter module to turn the LED off when
 *          something is placed between the gap of the module
 */

int Led = 13; //define the led's port
int buttonpin = 3; //define the port of light blocking module
int val; //define digital variable val

void setup() {
  pinMode(Led, OUTPUT); //define digital variable val
  pinMode(buttonpin, INPUT); //define light blocking module as a output port
}
void loop() { 
  val = digitalRead(buttonpin); //read the value of the digital interface 3 assigned to val
  if (val == HIGH) //when something is placed between the gap, the light and current is cut 
  {
    digitalWrite(Led, LOW);
  }
  else {
    digitalWrite(Led, HIGH);
  }
}
