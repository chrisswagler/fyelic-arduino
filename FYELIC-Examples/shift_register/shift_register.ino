/*
   modified 11 March 2021
   by Chris Swagler
   purpose: to use a shift register (74HC595) with 8 LED outpus, while only taking up 3 Arduino pins

   check out these useful tutorials/resources:
   https://lastminuteengineers.com/74hc595-shift-register-arduino-tutorial/
   https://www.arduino.cc/en/Tutorial/Foundations/ShiftOut
*/

int latchPin = 5;
int clockPin = 6;
int dataPin = 4;

byte leds = 0;

void setup()
{
  pinMode(latchPin, OUTPUT); //corresponds to pin 12 (RCLK or ST_CP) on the 74HC595
  pinMode(dataPin, OUTPUT);  //corresponds to pin 14 (SER or DS) on the 74HC595
  pinMode(clockPin, OUTPUT); //corresponds to pin 11 (SRCLK or SH_CP) on the 74HC595
}

void loop()
{
  leds = 0; //initially sets all the LEDs off
  updateShiftRegister();
  delay(500);

  //loops through the 8 LEDs, setting the corresponding bit in _leds_ to 1 to turn the pin on
  for (int i = 0; i < 8; i++)
  {
    bitSet(leds, i);
    updateShiftRegister();
    delay(500);
  }

  /*
     Now say you wanted to turn on/off specific pins. We can use binary to choose which pins!
     We can represent binary values using 0bXXXX where X's are the 1/0 digits. Since we have
     8 pins to control in this example, our binary number should have 8 places. The far left bit
     corresponds to pin Q0/QA, while the 8th is Q7/QH.
  */

  leds = 0b10101110; //this specific value will turn on the 1st, 3rd, 5th, 6th, 7th LEDs
  updateShiftRegister();
  delay(1000);

  leds = ~0b10101110; //this specific value is the inverse of that, so it will be 2nd, 4th, 8th
  updateShiftRegister();
  delay(1000);
}

//function that shifts the data to the shift register and updates
void updateShiftRegister()
{
  digitalWrite(latchPin, LOW); //sets the latch pin to low to make modifications
  shiftOut(dataPin, clockPin, LSBFIRST, leds); //shifts the value of _leds_
  digitalWrite(latchPin, HIGH); //sets the latch pin to high
}
