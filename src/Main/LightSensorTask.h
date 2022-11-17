#ifndef __LIGHTSENSORTASK__
#define __LIGHTSENSORTASK__

#include "Task.h"

class LightSensorTask: public Task {

  int pin;
  double valueInVolt;

  public:

  LightSensorTask(int pin);

  void init(int period);
  void tick();
  double getIntensity();

};

#endif
