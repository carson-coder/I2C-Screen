#include <Arduino.h>
#include "screen.h"
#include "utils.h"

void loop() {
    show_text(get_serial_data);
}

void setup() {
    screen_setup();
}