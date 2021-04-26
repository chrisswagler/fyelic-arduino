/*
   modified 26 April 2021
   by Chris Swagler
   purpose: to use a thermistor as a temperature sensor, reading in the analog value
            and calculating the corresponding resistance every second

   Note: higher temperature readings will correspond to lower analog reading and resistance

*/

// the value of the 'other' resistor
int SERIESRESISTOR = 10000;

int THERMISTORPIN = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float reading;

  reading = analogRead(THERMISTORPIN);

  Serial.print("Analog reading ");
  Serial.println(reading);

  // convert the value to resistance
  reading = (1023 / reading)  - 1;     // (1023/ADC - 1)
  reading = SERIESRESISTOR / reading;  // 10K / (1023/ADC - 1)
  Serial.print("Thermistor resistance ");
  Serial.println(reading);

  delay(1000);
}
