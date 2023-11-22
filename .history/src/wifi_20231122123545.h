#include <Arduino.h>
#include <ESP8266WiFi.h>        // Include the Wi-Fi library

void wifi_setup(char* SSID, char* PASS) {
    Serial.begin(115200);         // Start the Serial communication to send messages to the computer
    delay(10);
    Serial.println('\n');
    
    WiFi.begin(SSID, PASS);             // Connect to the network
    Serial.print("Connecting to ");
    Serial.print(SSID); Serial.println(" ...");

    int i = 0;
    while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
        delay(1000);
        Serial.print(i++); Serial.print(' ');
    }

    
}