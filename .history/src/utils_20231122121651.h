#include <Arduino.h>
#include "screen.h"

char data[50] = {
    '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
    '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
    '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
    '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
    '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};
char lastbit = '\0';

int i = 0;


void loop() {
    if (Serial.available()) {
        lastbit = Serial.read();
        if (lastbit == '\r') {
            lastbit = '\n';
            Serial.print('\r');
        }
        if (lastbit == 127) {
            i--;
            data[i] = '\0';
            Serial.print('\b');
            return;
        }
        if (lastbit == '/') {
            i = 0;
            Serial.println("\033[0H\033[0J");
            lastbit = '\0';
            show_text(data);
            for (int d = 0; d < 50; d++) {
                data[d] = '\0';
            }
            return;
        }
        Serial.print(lastbit);
        data[i] = lastbit;
        i++;
    }
}

void setup() {
    screen_setup();
}