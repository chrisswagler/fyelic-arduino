/*
   modified 24 March 2021
   by Chris Swagler
   purpose: to use a reed swtich to change the blink speed of the LED
            when a magnetic field is present

   Note: when a magnet is not present, the value read by the sensor will be large (~1023)
         but when a magnet is present, the value will be much smaller. The potentiometer
         can be used to adjust the sensitivity
*/
int  sensorPin = A0;     // select the input  pin for  the potentiometer
int  ledPin = 13;   // select the pin for  the LED
int  sensorValue = 0;  // variable to  store  the value  coming  from  the sensor

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue =  analogRead(sensorPin);
  digitalWrite(ledPin,  HIGH);
  delay(sensorValue);
  digitalWrite(ledPin,  LOW);
  delay(sensorValue);
  Serial.println(sensorValue,  DEC);
}
