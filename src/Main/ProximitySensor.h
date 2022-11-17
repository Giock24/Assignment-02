#ifndef __PROXIMITYSENSOR__
#define __PROXIMITYSENSOR__

#include "Task.h"

class ProximitySensor: public Task {

  int pin;
  bool detectedStatus;
  enum { DETECTED, NOT_DETECTED } state;

  private:

  void calibratePIR();

  public:

  ProximitySensor(int pin);
  bool isSomeoneDetected();
  void init(int period);
  void tick();
};

#endif