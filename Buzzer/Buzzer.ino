/*
  modified 29 Nov 2020
  by Chris Swagler
  purpose: beep the buzzer on and off with one second delays
  wire diagram:
     - Note : the piezo buzzer is polarized! Double check the + is wired to 
              the pin and - is wired to ground
*/

int speakerPin = 10;               //the pin that buzzer is connected to

void setup()
{
  pinMode(speakerPin, OUTPUT);    //set the output pin for the speaker
}

void loop()
{
  tone(speakerPin, 1000); // Send 1KHz sound signal
  delay(1000);

  noTone(speakerPin);     // Stop sound
  delay(1000);
}
