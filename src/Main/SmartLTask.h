#ifndef __SMARTLTASK__
#define __SMARTLTASK__

#include "Task.h"
#include "ProximitySensor.h"

class SmartLTask: public Task {

  int pin;
  Light* led;
  ProximitySensor* PIR;
  // LightSensor* LS;
  enum { ON, TURNING_OFF, OFF} state;

  public:

  SmartLTask(int pin);
  void init(int period);
  void tick();

}

#endif