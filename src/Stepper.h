
#include <Arduino.h>

#pragma once


class Stepper {
    private:
    byte a0Pin;
    byte a1Pin;
    byte b0Pin;
    byte b1Pin;
    int pulseMs;
    int curStep;
    public:
    Stepper(byte a0Pin, byte a1Pin, byte b0Pin, byte b1Pin, int pulseMs) {
        this->a0Pin = a0Pin;
        this->a1Pin = a1Pin;
        this->b0Pin = b0Pin;
        this->b1Pin = b1Pin;
        this->pulseMs = pulseMs;
        pinMode(a0Pin, OUTPUT);
        pinMode(a1Pin, OUTPUT);
        pinMode(b0Pin, OUTPUT);
        pinMode(b1Pin, OUTPUT);
        digitalWrite(a0Pin, 0);
        digitalWrite(a1Pin, 0); 
        digitalWrite(b0Pin, 0); 
        digitalWrite(b1Pin, 0); 
    }
    void step(bool backward) {
        if (backward) {
            curStep--;
            if (curStep < 0) {
            curStep = 3;
            }
        } else {
            curStep++;
            if (curStep > 3) {
            curStep = 0;
            }
        }
        digitalWrite(a0Pin, curStep==0);
        digitalWrite(a1Pin, curStep==2); 
        digitalWrite(b0Pin, curStep==1); 
        digitalWrite(b1Pin, curStep==3); 
        delay(pulseMs);
        digitalWrite(a0Pin, 0);
        digitalWrite(a1Pin, 0); 
        digitalWrite(b0Pin, 0); 
        digitalWrite(b1Pin, 0); 
    }

};