#ifndef __LCD__
#define __LCD__

class LCD {

  int pin1, pin2;

  public:

  LCD();
  void showText(char* text);
};

#endif