#ifndef __SONAR__
#define __SONAR__

#include "Const.h"

class Button {

  int pin;
  bool statusB;

  public:

  Button(int pin);
  bool buttonIsPressed();

};

#endif