#include <Arduino.h>
#include "screen.h"
//#include "serial.h"
#include "wifi.h"
#include "config.h"

void loop() {
    //show_text(get_serial_data());
    wifi_loop();
}

void setup() {
    Serial.begin(9600); 
    Serial.setDebugOutput(true);
    struct rst_info *rtc_info = system_get_rst_info();
    os_printf("reset reason: %x\n", rtc_info->reason);
    if (rtc_info->reason == REASON_WDT_RST ||
    rtc_info->reason == REASON_EXCEPTION_RST ||
    rtc_info->reason == REASON_SOFT_WDT_RST) {
        if (rtc_info->reason == REASON_EXCEPTION_RST) {
            os_printf("Fatal exception (%d):\n", rtc_info->exccause);
        }
        os_printf("epc1=0x%08x, epc2=0x%08x, epc3=0x%08x, excvaddr=0x%08x, depc=0x%08x\n", rtc_info->epc1, rtc_info->epc2, rtc_info->epc3, rtc_info->excvaddr, rtc_info->depc);
    }
    screen_setup();
    //serial_setup();
    wifi_setup(ssid, password);
}