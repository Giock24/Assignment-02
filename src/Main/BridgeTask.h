#ifndef __BRIDGETASK__
#define __BRIDGETASK__

#include "Task.h"
#include "Const.h"
#include "Led.h"
#include "LCD.h"
#include "Sonar.h"

// value of Water Level to modify
#define WL1 2
#define WL2 5
#define WL_MAX 6

class BridgeTask: public Task {

  Sonar* S;
  // ServoMotor* SM;
  // PotentiometerTask* Pot;
  Light* LC;
  Light* LB;
  // Button* B;
  LCD* lcd;
  enum tipo { NORMAL, PRE_ALARM, ALARM, HUMAN_CONTROL } state;


  private:

  void changeToNormal();
  void changeToPreAlarm();
  void changeToAlarm();

  public:

  BridgeTask(int pin1, int pin2, int buttonPin, Sonar* sonar);
  void init(int period);
  void tick();
  enum tipo getStatus();

};

#endif
