/*
   modified 24 March 2021
   by Chris Swagler
   purpose: to use the digital temperature module from Elegoo

   Note: this module uses a thermister, which is a type of resistor
         whose resistance is temperature dependent. If you hold the 
         thermister while the code is running, you'll see the 
         resistance change in the serial monitor output
*/

byte NTCPin = A0;
#define SERIESRESISTOR 10000
#define NOMINAL_RESISTANCE 10000
#define NOMINAL_TEMPERATURE 25
#define BCOEFFICIENT 3950

void setup() {
  Serial.begin(9600);
}
void loop() {
  float ADCvalue;
  float Resistance;
  ADCvalue = analogRead(NTCPin);
  Serial.print("Analoge ");
  Serial.print(ADCvalue);
  Serial.print(" = ");
  //convert value to resistance
  Resistance = (1023 / ADCvalue) - 1;
  Resistance = SERIESRESISTOR / Resistance;
  Serial.print(Resistance);
  Serial.println(" Ohm");

  float steinhart;
  steinhart = Resistance / NOMINAL_RESISTANCE; // (R/Ro)
  steinhart = log(steinhart); // ln(R/Ro)
  steinhart /= BCOEFFICIENT; // 1/B * ln(R/Ro)
  steinhart += 1.0 / (NOMINAL_TEMPERATURE + 273.15); // + (1/To)
  steinhart = 1.0 / steinhart; // Invert
  steinhart -= 273.15; // convert to C

  Serial.print(steinhart);
  Serial.println(" oC");
  delay(1000);
}
