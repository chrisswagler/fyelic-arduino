/*
   modified 2 April 2021
   by Chris Swagler
   purpose: to use a simple switch to turn on/off the builtin LED

   Note: if you're using the switch from your kit, the middle pin should
         be grounded, but the data pin can be connected to either side. 
*/
int switchPin = 7;

void setup() {
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(switchPin) == LOW) {          //if the switch is on...
    Serial.println("switch activated!");
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}
