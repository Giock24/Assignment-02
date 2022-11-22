#include "ServoMotor.h"
#include "Arduino.h"

ServoMotor::ServoMotor(int pin) {
  this->myservo.attach(pin);
}

void ServoMotor::move(int angle){
  this->myservo.write(angle);
  this->currentAngle += angle;
  delay(15); // Questo delay è omissibile in caso di problemi dovuti all'utilizzo di milies(). Eventualmente riguardare quale può essere un lasso di tempo appropriato da dare al servo per cambiare il suo angolo.
}

int ServoMotor::getAngle(){
  return this->currentAngle;
}