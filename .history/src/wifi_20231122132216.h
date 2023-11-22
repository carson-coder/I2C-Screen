#include <Arduino.h>
#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include "screen.h"
#include <iostream>

using namespace std;

String tmp;

void wifi_setup(String SSID, const char* PASS) {
    WiFi.begin(SSID, PASS);             // Connect to the network
    strcmp("Connecting to", tmp);
    strcat(tmp, SSID);
    show_text(tmp);

    while (WiFi.status() != WL_CONNECTED) {}
}