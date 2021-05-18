/*
   modified 18 May 2021
   by Chris Swagler
   purpose: to use the Neopixel Ring to display color patterns

   Note: the Neopixel library was used to control the rings.
         The code for the strips is the same as for the rings.
         ***For more detailed information, check out the examples from the Neopixel library***
         *The sketch strandtest has a bunch of fun color functions that you can use

   Wiring note: if you want to connect multiple strips or multiple rings, the DATA OUT of one
                Neopixel must connect to the DATA IN of the next. It's important to note the direction
                of the data flow and that you must connect OUT->IN
*/

#include <Adafruit_NeoPixel.h>

//the pin that the LEDs are connected to
int LED_PIN = 6;

//easily adjustable constant for how many individual LEDs are in your ring
int LED_COUNT = 12;

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags

void setup() {
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
}

void loop() {
  //we can define colors by their RGB values
  uint32_t red = strip.Color(255, 0, 0);
  uint32_t green = strip.Color(0, 255, 0);
  uint32_t blue = strip.Color(0, 0, 255);

  //loops through each of the pixels and sets that pixel to red
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, red);
    strip.show();
    delay(500);
  }

  //loops through every other pixel (changed for loop increment)
  //in the other direction and sets pixel to green
  for (int i = strip.numPixels(); i >= 0; i -= 2) {
    strip.setPixelColor(i, green);
    strip.show();
    delay(500);
  }

  //let's manually set the remaining red pixels to blue immediately
  //NOTE: if you changed the LED_COUNT variable to a different number, this section will likely not work
  //The purpose of this section was to show that individual LEDs could be addressed
  strip.setPixelColor(1, blue);
  strip.setPixelColor(3, blue);
  strip.setPixelColor(5, blue);
  strip.setPixelColor(7, blue);
  strip.setPixelColor(9, blue);
  strip.setPixelColor(11, blue);
  strip.show();
  delay(2000);

  //clear the strip after the end of this sequence
  strip.clear();
}
