#ifndef __LIGHTSENSOR__
#define __LIGHTSENSOR__

class LightSensor {

  int pin;

  public:

  LightSensor(int pin);
  double getIntensity();

};

#endif