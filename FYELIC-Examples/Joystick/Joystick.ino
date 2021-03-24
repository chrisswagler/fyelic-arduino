/*
   modified 24 March 2021
   by Chris Swagler
   purpose: to use the joystick to obtain x, y coordinates and if the
            joystick is pressed or not

   Note:
*/

int VRx = A0;
int VRy = A1;
int ZPin = 7;
int value = 0;

void setup() {
  pinMode(ZPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  value = analogRead(VRx);
  Serial.print("X:");
  Serial.print(value, DEC);
  value = analogRead(VRy);
  Serial.print(" | Y:");
  Serial.print(value, DEC);
  value = digitalRead(ZPin);
  Serial.print(" | Z: ");
  Serial.println(value, DEC);
  delay(100);
}
