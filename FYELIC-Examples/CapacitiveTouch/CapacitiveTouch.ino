/*
   modified 16 March 2021
   by Chris Swagler
   purpose: to use the AT42QT capacitive touch sensor to light an LED when touched
  Hardware connections:

  Uno Pin    AT42QT101X Board  Function

  +5V        VDD               Power supply
  GND        GND               Ground
  2          OUT               Capacitive touch state output
*/

const int TOUCH_BUTTON_PIN = 2;  // Input pin for touch state
const int LED_PIN = 13;          // Pin number for LED

int buttonState = 0;             // Variable for reading button

void setup() {

  // Configure button pin as input
  pinMode(TOUCH_BUTTON_PIN, INPUT);

  // Configure LED pin as output
  pinMode(LED_PIN, OUTPUT);

}

void loop() {

  // Read the state of the capacitive touch board
  buttonState = digitalRead(TOUCH_BUTTON_PIN);

  // If a touch is detected, turn on the LED
  if (buttonState == HIGH) {
    digitalWrite(LED_PIN, HIGH);
    //note: if wired as described above, the sensor's LED should also illuminate
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
