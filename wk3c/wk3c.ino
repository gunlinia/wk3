

#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`

#include "images.h"

SSD1306Wire  display(0x3c, 21, 22);
int potpin = 2;
int val = 0;

#define DEMO_DURATION 3000
typedef void (*Demo)(void);

int demoMode = 0;
int counter = 1;

void setup() {
  Serial.begin(9600);
  display.init();

  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);

}

void drawFontFaceDemo() {
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(20, 15, "Read Value is:");
    display.setFont(ArialMT_Plain_24);
    display.drawString(40, 25, String(analogRead(potpin)));
}
Demo demos[] = {drawFontFaceDemo};

void loop() {
  display.clear();
  val = analogRead(potpin);
  Serial.println(val);
  demos[demoMode]();
  display.display();
  delay(50);
}

