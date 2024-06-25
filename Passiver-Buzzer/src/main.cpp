// #################################################################################
//          Source: https://esp32io.com/tutorials/esp32-button-piezo-buzzer
// #################################################################################

#include <Arduino.h>
#include "notes.h"

#define BUZZER_PIN 25

int melody[] = {
        NOTE_E5, NOTE_E5, NOTE_E5,
        NOTE_E5, NOTE_E5, NOTE_E5,
        NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
        NOTE_E5,
        NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
        NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
        NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
        NOTE_D5, NOTE_G5
};

int noteDurations[] = {
        8, 8, 4,
        8, 8, 4,
        8, 8, 8, 8,
        2,
        8, 8, 8, 8,
        8, 8, 8, 16, 16,
        8, 8, 8, 8,
        4,
};

void buzzer();

void setup() {
    pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
//    tone(BUZZER_PIN, 440, 200);
//    noTone(BUZZER_PIN);
    buzzer();
    delay(3000);
}

void buzzer() {
    int size = sizeof(noteDurations) / sizeof(int);

    for (int thisNote = 0; thisNote < size; thisNote++) {
        int noteDuration = 1000 / noteDurations[thisNote];
        tone(BUZZER_PIN, melody[thisNote], noteDuration);

        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);

        noTone(BUZZER_PIN);
    }
}
