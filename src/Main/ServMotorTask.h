#ifndef __SERVMOTORTASK__
#define __SERVMOTORTASK__

#include "Task.h"
#include "SonarTask.h"
#include "ServoMotor.h"

class ServMotorTask: public Task {

  SonarTask* mysonar;
  ServoMotor* myservo;
  //enum controlState { AUTO, MANUAL } Cstate;
  enum valveState { OPEN, CLOSE } Vstate;

  private:
  bool checkWater();

  public:
  ServMotorTask(ServoMotor* servo, SonarTask* sonar);
  void init(int period);
  void tick();
  int openingAngle();

};

#endif
