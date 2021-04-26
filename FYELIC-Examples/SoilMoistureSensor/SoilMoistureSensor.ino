/*
    modified 26 April 2021
    by Chris Swagler
    purpose: to use the soil moisture sensor to take readings every second
*/

int val = 0; //value for storing moisture value
int soilPin = A0;//Declare a variable for the soil moisture sensor
int soilPower = 7;//Variable for Soil moisture Power

//Rather than powering the sensor through the 3.3V or 5V pins,
//we'll use a digital pin to power the sensor. This will
//prevent corrosion of the sensor as it sits in the soil.

void setup() {
  Serial.begin(9600);

  pinMode(soilPower, OUTPUT); //Set D7 as an OUTPUT
  digitalWrite(soilPower, LOW); //Set to LOW so no power is flowing through the sensor
}

void loop() {
  Serial.print("Soil Moisture = ");
  //get soil moisture value from the function below and print it
  Serial.println(readSoil());
  delay(1000);//take a reading every second
}

//This is a function used to get the soil moisture content
int readSoil() {
  digitalWrite(soilPower, HIGH);//turn D7 "On"
  delay(10);//wait 10 milliseconds
  val = analogRead(soilPin);//Read the SIG value form sensor
  digitalWrite(soilPower, LOW);//turn D7 "Off"
  return val;//send current moisture value
}
