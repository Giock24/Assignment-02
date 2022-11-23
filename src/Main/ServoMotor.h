#ifndef __SERVOMOTOR__
#define __SERVOMOTOR__

#include <Servo.h>

class ServoMotor{

  int currentAngle;
  Servo myservo;    // Oggetto di riferimento per interagire con il ServoMotore via la lib Servo.h.

  public:
  ServoMotor(int pin);
  void move(int angle);
  int getAngle();

};

#endif