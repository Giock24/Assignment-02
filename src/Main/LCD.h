#ifndef __LCD__
#define __LCD__

#include <LiquidCrystal_I2C.h>

class LCD {

  LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27,20,4);

  public:

  LCD();
  void turnOn();
  void turnOff();
  void write(int row, int col, char* text);
  void clear();
  void clear(int row, int col, int length);
};

#endif