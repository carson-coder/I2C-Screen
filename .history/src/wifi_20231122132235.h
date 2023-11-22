#include <Arduino.h>
#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include "screen.h"
#include <iostream>

using namespace std;

String tmp;

void wifi_setup(String SSID, const char* PASS) {
    WiFi.begin(SSID, PASS);
    show_text("Connecting to " + SSID);

    while (WiFi.status() != WL_CONNECTED) {}
}