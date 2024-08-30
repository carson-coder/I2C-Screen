#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 1

// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define DATA_PIN 12

// Define the array of leds
CRGB leds[NUM_LEDS];

void light_setup() { 
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

int hue = 0;

void light_loop() { 
  leds[0] = CHSV( hue, 255, 255);
  FastLED.show();
  hue++;
  if (hue > 255) {hue = 0;}
//   delay(10);
}