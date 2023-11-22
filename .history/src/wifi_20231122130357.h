#include <Arduino.h>
#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include "screen.h"
#include <iostream>

using namespace std;

void wifi_setup(const char* SSID, const char* PASS) {
    WiFi.begin(SSID, PASS);             // Connect to the network
    show_text("Connecting to " + SSID);

    while (WiFi.status() != WL_CONNECTED) {}
}