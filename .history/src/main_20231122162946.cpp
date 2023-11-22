#include <Arduino.h>
#include "screen.h"
//#include "serial.h"
#include "wifi.h"

String ssid = "SSID";         // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "Password";     // The password of the Wi-Fi network

void loop() {
    //show_text(get_serial_data());
}

void setup() {
    Serial.begin(9600); 
    screen_setup();
    //serial_setup();
    wifi_setup(ssid, password);
}