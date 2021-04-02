/******************************************
  Website: www.elegoo.com

  Time:2017.12.12

 ******************************************/
/*
   modified 24 March 2021
   by Chris Swagler
   purpose: to use the active buzzer by creating square waves

   Note: this sketch creates a really rough and ear ringing tone.
         The sketch essentially creates a square wave in the for loops by
         switching between HIGH and LOW for a specified delay. If you wanted
         to use a different pitch, you could change the delay, which would 
         change the frequency (pitch) of the sound generated

   This code can also be used for the passive buzzer. The passive buzzer actually
   can only work with square waves, wheras this active buzzer can be driven by
   both a DC signal and a square wave
*/
int buzzer = 8;//the pin of the active buzzer
void setup() {
  pinMode(buzzer, OUTPUT); //initialize the buzzer pin as an output
}
void loop() {
  unsigned char i;
  //output an frequency
  for (i = 0; i < 80; i++)
  {
    digitalWrite(buzzer, HIGH);
    delay(1);//wait for 1ms
    digitalWrite(buzzer, LOW);
    delay(1);//wait for 1ms
  }
  //output another frequency
  for (i = 0; i < 100; i++)
  {
    digitalWrite(buzzer, HIGH);
    delay(5);//wait for 5ms
    digitalWrite(buzzer, LOW);
    delay(5);//wait for 5ms
  }
}
