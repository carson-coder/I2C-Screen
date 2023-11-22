#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 // Number of snowflakes in the animation example

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16
static const unsigned char PROGMEM logo_bmp[] =
{
    0b01010101, 0b01010101,
    0b10101010, 0b10101010,
    0b01010101, 0b01010101,
    0b10101010, 0b10101010,
    0b01010101, 0b01010101,
    0b10101010, 0b10101010,
    0b01010101, 0b01010101,
    0b10101010, 0b10101010,
    0b01010101, 0b01010101,
    0b10101010, 0b10101010,
    0b01010101, 0b01010101,
    0b10101010, 0b10101010,
    0b01010101, 0b01010101,
    0b10101010, 0b10101010,
    0b01010101, 0b01010101,
    0b10101010, 0b10101010
}; // 16x16

char* data;
char lastbit = '\0';

void loop() {
    if (Serial.available()) {
        lastbit = Serial.read();
        int i = 0;
        while (lastbit != '/') {
            data[i] = lastbit;
            lastbit = Serial.read();
            i++;
        }
        lastbit = '\0';
        display.clearDisplay();
        display.setTextSize(2); // Draw 2X-scale text
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(0, 0);
        display.println(data);
        display.display();
    }
}

void setup() {
    digitalWrite(0, HIGH);
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.

  // Clear the buffer
  display.clearDisplay();
  display.display();

}