#include "Potentiometer.h"
#include "Arduino.h"

Potentiometer::Potentiometer(int pin){
  this->pin = pin;
  this->val = 0;
}

int Potentiometer::ptmAngle(){
  val = analogRead(this->pin);
  return map(val, 0, 1023, 0, 180);
}