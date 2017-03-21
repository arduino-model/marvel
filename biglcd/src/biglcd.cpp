#include "../lib/LCD12864R/LCD12864R.h"
#include "Arduino.h"

#define LED 13

char buffer[16];

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void setup() 
{
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
    LCDA.Initialise(); //Pantalla
    LCDA.CLEAR();
    delay(100);
    LCDA.DisplaySig(0,0,0x20);
    delay(100);
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void loop() 
{

    digitalWrite(LED,HIGH);
    printstring(0,"Hello everyone!");
    printstring(1,"How do you do?");
    printstring(2,"How is it going?");

    if (Serial.available() > 0) {
        Serial.readBytes(buffer, sizeof(buffer));
        printstring(3,buffer);
        Serial.println("I received: ");
    }

}

void printstring(int X,char *str){
    LCDA.DisplayString(X,0,str, strlen(str));
}



