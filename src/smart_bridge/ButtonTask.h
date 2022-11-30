#ifndef __BUTTONTASK__
#define __BUTTONTASK__

#include "Task.h"
#include "Button.h"
#include "Arduino.h"

class ButtonTask: public Task{
  Button* btn;
  bool oldstate;
  bool newstate;

  public:
  ButtonTask(Button* btn);
  void init(int period);
  void tick();
  bool wasPressed();

};

#endif