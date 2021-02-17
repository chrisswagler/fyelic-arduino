/*
  modified 29 Nov 2020
  by Chris Swagler
  purpose: display to the serial monitor the position of the potentiometer
  wire diagram : 
     - Note : the potentiometer is not polarized, so it can be installed in either direction. However,
              swapping the 5V and GND pints will reverse its behavior
*/

int potPin = A0;        //use the ANALOG pin A0 for the potentiometer
int potPosition;       //this variable will hold a value based on the position of the potentiometer

void setup()
{
  Serial.begin(9600);       //start a serial connection with the computer
}

void loop()
{
  //read the position of the pot
  potPosition = analogRead(potPin);    //set potPosition to a number between 0 and 1023 based on how far the knob is turned
  Serial.println(potPosition);     //print the value of potPosition in the serial monitor on the computer
  delay(100);
}
