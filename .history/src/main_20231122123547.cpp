#include <Arduino.h>
#include "screen.h"
#include "serial.h"

const char* ssid     = "SSID";         // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "PASSWORD";     // The password of the Wi-Fi network

void loop() {
    show_text(get_serial_data());
}

void setup() {
    screen_setup();
    serial_setup();
}