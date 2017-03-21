#include <Arduino.h>
#include "../../../../../../../opt/arduino-1.8.1/hardware/arduino/avr/cores/arduino/USBAPI.h"
#include "../../../../../../../opt/arduino-1.8.1/hardware/arduino/avr/cores/arduino/HardwareSerial.h"

const int VT1=9;
const int VT2=10;
const int VT3=3;
const int VT4=11;
const int VT5=5;
const int VT6=6;

const int ary[6][3] = {
  {VT6,VT1,VT5}, //first step
  {VT1,VT3,VT5}, //second step
  {VT5,VT3,VT4}, //third step
  {VT3,VT2,VT4}, //fourth step
  {VT4,VT2,VT6}, //fifth step
  {VT2,VT1,VT6}  //sixth step
};

unsigned int t;
int range = 0;
const unsigned int ranges[5][2] = {
  {999999,16384},
  {16383,5000},
  {4999,2200},
  {2199,1154},
  {1153,0},
};


void setup() 
{
  Serial.begin(9600);
  int VTs[6] = {VT1,VT2,VT3,VT4,VT5,VT6};
  for (int i = 0; i < 6; ++i) {
    pinMode(VTs[i],OUTPUT);
  }  
}

void doSteps(unsigned int t1){
  for(int i = 0; i < 6; i++) {
    digitalWrite(ary[i][0],LOW);
    digitalWrite(ary[i][1],HIGH);
    digitalWrite(ary[i][2],HIGH);

    if(t1>16000){
      delay((unsigned long) (t1 / 1000));
    } else {
      delayMicroseconds(t1);
    }
  }
}

int getRange(int num){

    for(int i = 0; i < 5; i++) {
        int max = ranges[i][0];
        int min = ranges[i][1];
        if (num <= max && !(num < min)) {
          return i;
        }
    }
}

void loop()
{
    t=60000;
    Serial.print("Range; Value is:"); Serial.println(range);
  while(true){
        range = getRange(t);
        switch(range){
            case 0:
                t=t-5000;
                break;
            case 1:
                t=t-50;
                break;
            case 2:
                t=t-9;
                break;
            case 3:
                t=t-1;
                break;
            case 4:
                t=t+3                                                                                                 ;
                break;
            default:break;
        }
        Serial.print("T:"); Serial.println(t);
        Serial.print("Range; Value is:"); Serial.println(range);
        doSteps(t);
  }

}
