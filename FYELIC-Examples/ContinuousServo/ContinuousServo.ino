/*
 * modified 19 March 2021
 * by Chris Swagler
 * purpose: to drive the continuous servo motor
 * 
 * Note: the servo range is 0-180. O and 180 drive the servo at full speed
 *       in different directions. At 90, the servo should be stopped. However,
 *       this value might need to be adjusted slightly
 */
#include <Servo.h>
Servo myservo;

void setup() {
  myservo.attach(9); //attaches the servo on pin 9 
}

void loop() {
  myservo.write(0); //servo drives full speed in one direction
  delay(1000);
  myservo.write(45); //servo drives half speed in one direction
  delay(1000);
  myservo.write(90); //servo stopped
  delay(1000);
  myservo.write(135); //servo drives half speed in other direction
  delay(1000);
  myservo.write(180); //servo drives full speed in other direction
  delay(1000);
  myservo.write(90); //servo stopped
  delay(1000);
}
