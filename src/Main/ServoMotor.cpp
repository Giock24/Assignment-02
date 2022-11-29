#include "ServoMotor.h"
#include "Arduino.h"
#include <math.h>

ServoMotor::ServoMotor(int pin) {
  this->myservo.attach(pin);
}

void ServoMotor::move(int angle){
  float coeff = (2250.0-750.0)/180;
  //Serial.println("Motor angle: "+angle);
  this->myservo.write(750 + abs(angle)*coeff);
  
  //this->currentAngle += angle;
}
/*
int ServoMotor::getAngle(){
  return this->currentAngle;
}*/
