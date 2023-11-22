#include <Arduino.h>
#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include "screen.h"
#include <iostream>

using namespace std;

String tmp;

String _SSID;
const char * _PASS;

void wifi_setup(String SSID, const char* PASS) {
    _SSID = SSID;
    _PASS = PASS;
    WiFi.begin(SSID, PASS);
    show_text("Connecting to " + SSID);
}

void wifi_loop() {
    if (WiFi.status() == WL_CONNECTED) {
        show_text("Connected to " + _SSID + "\nIp: " + WiFi.localIP().toString());
    }
}