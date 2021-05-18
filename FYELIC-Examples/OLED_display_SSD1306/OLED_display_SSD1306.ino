/*
   modified 18 May 2021
   by Chris Swagler
   purpose: to use the 128 x 64 pixel OLED display (SSD1306 chip)

   Resources: https://lastminuteengineers.com/oled-display-arduino-tutorial/
              check out the above link for more detail on how to use the display and also
              how to do more fun functions like display shapes or images
*/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(-1);

void setup() {
  // initialize with the I2C addr 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  // Clear the buffer.
  display.clearDisplay();

  // Display Text
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("FYELIC");
  display.display();
  delay(2000);
  display.clearDisplay();

  // Display Inverted Text
  display.setTextColor(BLACK, WHITE); // 'inverted' text
  display.setCursor(0, 12);
  display.println("Inverted FYELIC");
  display.display();
  delay(2000);
  display.clearDisplay();

  // Changing Font Size
  display.setTextColor(WHITE);
  display.setCursor(0, 14);
  display.setTextSize(2);
  display.println("Big FYELIC");
  display.display();
  delay(2000);
  display.clearDisplay();

  // Display Numbers
  display.setTextSize(1);
  display.setCursor(0, 16);
  display.println(368);
  display.display();
  delay(2000);
  display.clearDisplay();

  // Scroll full screen
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.println("Full screen");
  display.println("scrolling!");
  display.println("weeeee!");
  display.display();
  display.startscrollright(0x00, 0x07);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrollleft(0x00, 0x07);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrolldiagright(0x00, 0x07);
  delay(2000);
  display.startscrolldiagleft(0x00, 0x07);
  delay(2000);
  display.stopscroll();
  display.clearDisplay();

  // Scroll part of the screen
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.println("FYELIC");
  display.println("at");
  display.println("Northeastern COE.");
  display.display();
  display.startscrollright(0x00, 0x00);
  //didn't indicate display.stopscroll(), so this will keep scrolling on the display
}

void loop() {}
