#include <Arduino.h>

char data[50] = {
    '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
    '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
    '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
    '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
    '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};
char lastbit = '\0';

int i = 0;

char* get_serial_data() {
    while (true) {
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
                return data;
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
}

void serial_setup() {
    Serial.begin(9600);   
}