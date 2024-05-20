#include <Arduino.h>

int led1 = 32;
int led2 = 33;
int led3 = 25;
int led4 = 26;

int button1 = 36;
int button2 = 39;
int button3 = 34;
int button4 = 35;

void setup() {
    pinMode(button1, INPUT);
    pinMode(button2, INPUT);
    pinMode(button3, INPUT);
    pinMode(button4, INPUT);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    delay(50);
    digitalWrite(led1 ,digitalRead(button1));
    digitalWrite(led2 ,digitalRead(button2));
    digitalWrite(led3 ,digitalRead(button3));
    digitalWrite(led4 ,digitalRead(button4));
}