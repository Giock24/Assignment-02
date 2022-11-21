#ifndef __BRIDGETASK__
#define __BRIDGETASK__

#include "Task.h"
#include "Const.h"
#include "Led.h"
#include "LCD.h"

class BridgeTask: public Task {

  // Sonar* S;
  // ServoMotor* SM;
  // PotentiometerTask* Pot;
  Light* LC;
  Light* LB;
  // Button* B;
  LCD* lcd;
  enum { NORMAL, PRE_ALARM, ALARM, HUMAN_CONTROL } state;

  private:

  void changeToNormal();
  void changeToPreAlarm();
  void changeToAlarm();

  public:

  BridgeTask(int pin1, int pin2, int buttonPin);
  void init(int period);
  void tick();

};

#endif
