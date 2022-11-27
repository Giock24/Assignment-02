#ifndef __BUTTON__
#define __BUTTON__

class Button {

  int pin;
  bool statusB;

  public:
  Button(int pin);
  bool buttonIsPressed();

};

#endif