#include <Arduino.h>
#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include "screen.h"

void wifi_setup(char* SSID, char* PASS) {
    WiFi.begin(SSID, PASS);             // Connect to the network
    show_text("Connecting")

    int i = 0;
    while (WiFi.status() != WL_CONNECTED) {}
}