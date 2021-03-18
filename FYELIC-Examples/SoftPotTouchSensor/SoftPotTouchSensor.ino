/*
   modified 16 March 2021
   by Chris Swagler
   purpose: to use the SoftPot, (aka soft potentiometer or touch sensor) and display
            on the serial monitor where the force is applied on the sensor

  - Connect the softpot's outside pins to 5V and GND (the outer pin with an arrow
  indicator should be connected to GND).
  - Connect the middle pin to A0, with an additional 10k resistor to ground.

  As the voltage output of the softpot changes, a line graph printed to the
  serial monitor should match the wiper's position.
*/

const int SOFT_POT_PIN = A0; // Pin connected to softpot wiper

const int GRAPH_LENGTH = 40; // Length of line graph in serial monitor

void setup()
{
  Serial.begin(9600);
  pinMode(SOFT_POT_PIN, INPUT);
}

void loop()
{
  // Read in the soft pot's ADC value
  int softPotADC = analogRead(SOFT_POT_PIN);
  // Map the 0-1023 value to 0-40, or the desired graph length
  int softPotPosition = map(softPotADC, 0, 1023, 0, GRAPH_LENGTH);

  // Print a line graph:
  Serial.print("<"); // Starting end
  for (int i = 0; i < GRAPH_LENGTH; i++)
  {
    if (i == softPotPosition) Serial.print("|");
    else Serial.print("-");
  }
  Serial.println("> (" + String(softPotADC) + ")");

  delay(500);
}
