#include <Arduino.h>

const unsigned long t = 8;

//this pins have pulse-duration modulation PDM
const int VT1=9;
const int VT2=10;
const int VT3=3;
const int VT4=11;
const int VT5=5;
const int VT6=6;

void setup() {
    pinMode(VT1,OUTPUT);
    pinMode(VT2,OUTPUT);
    pinMode(VT3,OUTPUT);
    pinMode(VT4,OUTPUT);
    pinMode(VT5,OUTPUT);
    pinMode(VT6,OUTPUT);
}

void loop() {

    //First step
    digitalWrite(VT6,LOW);
    digitalWrite(VT1,HIGH);
    digitalWrite(VT5,HIGH);
    delay(t);

    //Second step
    digitalWrite(VT1,LOW);
    digitalWrite(VT3,HIGH);
    digitalWrite(VT5,HIGH);
    delay(t);

    //Third step
    digitalWrite(VT5,LOW);
    digitalWrite(VT3,HIGH);
    digitalWrite(VT4,HIGH);
    delay(t);

    //Fourth step
    digitalWrite(VT3,LOW);
    digitalWrite(VT2,HIGH);
    digitalWrite(VT4,HIGH);
    delay(t);

    //Fifth step
    digitalWrite(VT4,LOW);
    digitalWrite(VT2,HIGH);
    digitalWrite(VT6,HIGH);
    delay(t);

    //Six step
    digitalWrite(VT2,LOW);
    digitalWrite(VT1,HIGH);
    digitalWrite(VT6,HIGH);
    delay(t);

}