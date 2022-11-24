#ifndef __SERVMOTORTASK__
#define __SERVMOTORTASK__

#include "Task.h"
#include "Sonar.h"
#include "ServoMotor.h"

class ServMotorTask: public Task {

  Sonar* mysonar;
  ServoMotor* myservo;
  //enum controlState { AUTO, MANUAL } Cstate;
  enum valveState { OPEN, CLOSE } Vstate;

  private:
  bool checkWater();

  public:
  ServMotorTask(ServoMotor* servo, Sonar* sonar);
  void init(int period);
  void tick();
  int openingAngle();

};

#endif
