/*
 * modified 24 March 2021
 * by Chris Swagler
 * purpose: to use the hit sensor / tap module to turn the LED
 *          on when hit
 * 
 * Note: for the Elegoo sensor, I had to flick the plastic sensor part
 *       to get the on-board LED to flash
 */
int Led = 13;
int Shock = 3;
int val;

void setup() {
  pinMode(Led, OUTPUT);
  pinMode(Shock, INPUT);
}

void loop() {
  val = digitalRead(Shock);
  if (val == HIGH) {
    digitalWrite(Led, LOW);
  }
  else {
    digitalWrite(Led, HIGH);
  }
}
