/*
  modified 29 Nov 2020
  by Chris Swagler
  purpose: display to the serial monitor the temperature reading of the TMP36
  wire diagram : 
     - Note : make sure to double check the wiring of the temperature sensor!
              The sensor is polarized, so wiring incorrectly could cause it to become very hot
*/


int tempPin = A0;
float voltage = 0;                          //the voltage measured from the TMP36
float degreesC = 0;                         //the temperature in Celsius, calculated from the voltage
float degreesF = 0;                         //the temperature in Fahrenheit, calculated from the voltage

void setup() {
  Serial.begin(9600);
}

void loop() {

  voltage = analogRead(tempPin) * 0.004882814;   //convert the analog reading, which varies from 0 to 1023, back to a voltage value from 0-5 volts
  degreesC = (voltage - 0.5) * 100.0;       //convert the voltage to a temperature in degrees Celsius
  degreesF = degreesC * (9.0 / 5.0) + 32.0; //convert the voltage to a temperature in degrees Fahrenheit

  Serial.print("voltage: ");
  Serial.println(voltage);
  Serial.print("Celsius: ");
  Serial.println(degreesC);
  Serial.print("Fahrenheit: ");
  Serial.println(degreesF);
  Serial.println("***************");

  delay(1000);                              //delay for 1 second between each reading (this makes the display less noisy)
}
