#ifndef __PIRTASK__
#define __PIRTASK__

#include "Task.h"

#define CALIBRATION_TIME_SEC 10
#define T1 3 // max time in which nobody has been detected

class PIRTask: public Task {

  int timeNotDetected;
  int myPeriod;

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
