/*
  modified 29 Nov 2020
  by Chris Swagler
  purpose: cycle through different RGB colors with one second delays
*/

//LEDs are connected to these pins
int RedPin = 9;
int GreenPin = 10;
int BluePin = 11;

void setup() {
  Serial.begin(9600);           //start a serial connection with the computer

  //set the LED pins to output
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
}

void loop() {
  red(); //call the function for this color
  Serial.println("red");
  delay(1000); //hold for 1 second

  orange(); //call the function for this color
  Serial.println("orange");
  delay(1000); //hold for 1 second

  yellow(); //call the function for this color
  Serial.println("yellow");
  delay(1000); //hold for 1 second

  green(); //call the function for this color
  Serial.println("green");
  delay(1000); //hold for 1 second

  cyan(); //call the function for this color
  Serial.println("cyan");
  delay(1000); //hold for 1 second

  blue(); //call the function for this color
  Serial.println("blue");
  delay(1000); //hold for 1 second

  magenta(); //call the function for this color
  Serial.println("magenta");
  delay(1000); //hold for 1 second

  turnOff(); //call the function for this color
  Serial.println("off");
  delay(1000); //hold for 1 second
}

void red () {

  //set the LED pins to values that make red
  analogWrite(RedPin, 100);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 0);
}
void orange () {

  //set the LED pins to values that make orange
  analogWrite(RedPin, 100);
  analogWrite(GreenPin, 25);
  analogWrite(BluePin, 0);
}
void yellow () {

  //set the LED pins to values that make yellow
  analogWrite(RedPin, 80);
  analogWrite(GreenPin, 30);
  analogWrite(BluePin, 0);
}
void green () {

  //set the LED pins to values that make green
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 100);
  analogWrite(BluePin, 0);
}
void cyan () {

  //set the LED pins to values that make cyan
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 100);
  analogWrite(BluePin, 100);
}
void blue () {

  //set the LED pins to values that make blue
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 100);
}
void magenta () {

  //set the LED pins to values that make magenta
  analogWrite(RedPin, 100);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 100);
}
void turnOff () {

  //set all three LED pins to 0 or OFF
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 0);
}
