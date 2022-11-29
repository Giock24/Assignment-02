#ifndef __SERVOMOTOR__
#define __SERVOMOTOR__

#include "ServoTimer2.h"

class ServoMotor{

  //int currentAngle;
  ServoTimer2 myservo; // Oggetto di riferimento per interagire con il ServoMotore via la lib Servo.h.

  public:

  ServoMotor(int pin);
  void move(int angle);
  //int getAngle();
};

#endif
