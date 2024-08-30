#include <Arduino.h>
#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include "screen.h"
#include <iostream>

using namespace std;

String tmp;

String _SSID;
const char * _PASS;

WiFiServer wifiServer(80);

void wifi_setup(String SSID, const char* PASS) {
    _SSID = SSID;
    _PASS = PASS;
    WiFi.begin(SSID, PASS);
    show_text("Connecting to " + SSID);
    while (WiFi.status() != WL_CONNECTED) {delay(1);}
    show_text("Connected to " + _SSID + "\nIp: " + WiFi.localIP().toString());
    wifiServer.begin();
}

wl_status_t wifi_loop() {
    wl_status_t status = WiFi.status();

    //Serial.println(wifiServer.status());

    WiFiClient client = wifiServer.accept();
 
    if (client) {
        while (client.connected()) {
            char buffer[1024];
            int i = 0;
            while (client.available()>0) {
                char c = client.read();
                buffer[i++] = c;
            }
            show_text(buffer);
            delay(10);
        }
        client.stop();
        show_text("Computer Disconnected");
    }

    return status;
}