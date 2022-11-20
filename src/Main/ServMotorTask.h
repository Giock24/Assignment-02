#ifndef __SERVMOTORTASK__
#define __SERVMOTORTASK__

#include "Task.h"

class ServMotorTask: public Task {

  int pin;
  Sonar* MySonar;
  //enum controlState { AUTO, MANUAL } Cstate;
  enum valveState { OPEN, CLOSE } Vstate;

  public:
  ServMotorTask(int pin, Sonar* sonar);
  void init(int period);
  void tick();
  int GetRadious();

};

#endif
