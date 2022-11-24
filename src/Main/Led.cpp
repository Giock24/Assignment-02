#include "Led.h"
#include "Arduino.h"

Led::Led(int pin){
  this->pin = pin;
  pinMode(pin,OUTPUT);
  this->currentState = false;
}

void Led::switchOn(){
  digitalWrite(pin,HIGH);
  this->currentState = true;
  this->prevts = millis();
}

void Led::switchOff(){
  digitalWrite(pin,LOW);
  this->currentState = false;
  this->prevts = millis();
};

void Led::blink(double period) {
  long ts = millis() - this->prevts;
  Serial.println(ts);
  if (ts >= period) {
    if (this->currentState) {
      this->switchOff();
    } else {
      this->switchOn();
    }
  }
}
