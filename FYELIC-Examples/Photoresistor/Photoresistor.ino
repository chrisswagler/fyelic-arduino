/*
  modified 29 Nov 2020
  by Chris Swagler
  purpose: display to the serial monitor the photoresistor sensor reading
  wire diagram : 
     - Note : the resistor used is 10k. Also, the photoresistor is not polarized, so don't worry
              about which end to connect to power/ground
*/

int photoresistor;              //this variable will hold a value based on the brightness of the ambient light
int PRpin = A0;

void setup()
{
  Serial.begin(9600);               //start a serial connection with the computer
}

void loop()
{
  //read the brightness of the ambient light
  photoresistor = analogRead(PRpin);   //set photoresistor to a number between 0 and 1023 based on how bright the ambient light is
  Serial.println(photoresistor);    //print the value of photoresistor in the serial monitor on the computer
  delay(100);                       //short delay to make the printout easier to read
}
