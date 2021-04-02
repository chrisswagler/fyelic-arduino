/*
  Adafruit Arduino - Lesson 13. DC Motor
  modified 27 Nov 2020
  by Chris Swagler
  purpose: use the serial monitor to control the speed of a DC motor
  https://www.tutorialspoint.com/arduino/arduino_dc_motor.htm

  The motor should either be connected as shown in the wiring diagram, or
  by connecting it through the motor driver in your kit (like the yellow motors).
  Failing to do either of these methods could result in damaging your board.
  If you choose to use the motor driver, check out the YellowMotors sketch instead.
  FYELIC has 2N3904 transistors, 1N4001 diodes, and 330 ohm resistors that can be
  used for this circuit. 
*/
/*
   Note : these motors are different than servo and yellow motors in your kits
          Also, make sure the orientation of the transistor and diode are consistent
          with the wiring diagram as their polarity matters!
*/

int motorPin = 3; //connect DC motor to Pin 3

void setup()
{
  pinMode(motorPin, OUTPUT); //setup the motor to be an output
  Serial.begin(9600);
  Serial.println("Speed 0 to 255"); //print to serial monitor the range of inputs for motor speed
}


void loop()
{
  if (Serial.available())
  {
    int speed = Serial.parseInt(); //take the speed inputted in the serial monitor
    if (speed >= 0 && speed <= 255) //check if the speed is a valid input
    {
      analogWrite(motorPin, speed); //write the speed to the motor if the speed is valid
    }
  }
}
