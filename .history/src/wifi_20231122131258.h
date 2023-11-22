#include <Arduino.h>
#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include "screen.h"
#include <iostream>

using namespace std;

String tmp;

void wifi_setup(const char* SSID, const char* PASS) {
    WiFi.begin(SSID, PASS);             // Connect to the network
    tmp = "Connecting to ";
    show_text(tmp + str(SSID));

    while (WiFi.status() != WL_CONNECTED) {}
}