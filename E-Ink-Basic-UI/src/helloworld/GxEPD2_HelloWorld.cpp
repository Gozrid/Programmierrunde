#include <GxEPD2_BW.h>

GxEPD2_BW<GxEPD2_290_GDEY029T94, GxEPD2_290_GDEY029T94::HEIGHT> display(
        GxEPD2_290_GDEY029T94(/*CS=*/ SS, /*DC=*/ 0, /*RST=*/ 13, /*BUSY=*/10));

#include <Arduino.h>
#include <SPI.h>

const char HelloWorld[] = "Hello World!";
unsigned long previousMillis = 0;
const long interval = 60000;
int hour = 21;
int minute = 44;
char timeString[5];

void setup() {
    Serial.begin(115000);
    while (!Serial);
    Serial.println("GxEPD2 2.9-inch  e-ink display test start1");

    display.init(115200, true, 2, true); // USE THIS for Waveshare boards with "clever" reset circuit, 2ms reset pulse
    Serial.println("Display initialized");

    display.setRotation(1);
    display.setTextColor(GxEPD_BLACK);
    display.setFullWindow();
    display.firstPage();
    Serial.println("Starting display update");

    std::sprintf(timeString, "%02d:%02d", hour, minute);

    do {
        display.fillScreen(GxEPD_WHITE);
        display.setCursor(0, 0);
        display.setTextSize(2);
        display.print("Hello World");
        display.drawLine(0, 15, 300, 15, GxEPD_BLACK);
        display.setCursor(230, 0);
        display.setTextSize(2);
        display.print(timeString);
        display.setCursor(50, 60);
        display.setTextSize(2);
        display.print("Das ist ein Test");
        Serial.println("Display update done");
    } while (display.nextPage());
}

void loop() {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
        minute++;
        if (minute >= 60) {
            minute = 0;
            hour++;
        }
        if (hour >= 24) {
            hour = 0;
        }

        std::sprintf(timeString, "%02d:%02d", hour, minute);

        do {
            display.setPartialWindow(230, 0, 100, 10);
            display.fillScreen(GxEPD_WHITE);
            previousMillis = currentMillis;
            display.setCursor(230, 0);
            display.setTextSize(2);
            display.print(timeString);
            display.drawLine(230, 15, 300, 15, GxEPD_BLACK);
            display.nextPage();
            Serial.println(timeString);
        } while (display.nextPage());
    }
}