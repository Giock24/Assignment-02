#ifndef __LED__
#define __LED__

#include "Light.h"

class Led: public Light { 
public:
  Led(int pin);
  void switchOn();
  void switchOff();
  void blink(double period);    
private:
  int pin;
  bool currentState; // true = ON, false = OFF
  long prevts;  
};

#endif
