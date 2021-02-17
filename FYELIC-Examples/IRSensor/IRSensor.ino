/*
   modified 27 Nov 2020
   by Chris Swagler
   purpose: display to the serial monitor if the IR (line) sensor is covered or uncovered
   wire diagram : 
      - Note : Don't just blindly wire the IR sensor! Double check the markings on the
               sensor and wire VCC to 5 V, GND to ground, and OUT to the pin. Failure to
               wire the sensor correctly could damage the sensor
   https://create.arduino.cc/projecthub/Raushancpr/arduino-with-ir-sensor-1579b6
*/

int IRSensor = 2; // connect ir sensor to arduino pin 2

void setup()
{
  pinMode (IRSensor, INPUT); // sensor pin INPUT
  Serial.begin(9600);
}

void loop()
{
  int statusSensor = digitalRead (IRSensor);

  if (statusSensor == 1) {
    Serial.println("Uncovered");
  }

  else
  {
    Serial.println("Covered");
  }
  delay(100);
}
