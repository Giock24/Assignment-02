#ifndef __PIRTASK__
#define __PIRTASK__

#include "Task.h"

class PIRTask: public Task {

  int timeNotDetected; //
  int myPeriod; //

  int pin;
  bool detectedStatus;
  enum PIRState { DETECTED, NOT_DETECTED } state;

  private:

  void calibratePIR();


  public:

  PIRTask(int pin);

  void init(int period);
  void tick();
  bool isSomeoneDetected();
  bool isSomeoneDetectedT1();
  enum PIRState getState();
};

#endif
