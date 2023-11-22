#include <Arduino.h>
#include "screen.h"
#include "utils.h"

void loop() {
    show_text(get_serial_data());
}

void setup() {
    
  Serial.begin(9600);
    screen_setup();
}