#ifndef __BRIDGETASK__
#define __BRIDGETASK__

#include "Task.h"
#include "Const.h"
#include "Led.h"
#include "LCD.h"
#include "Sonar.h"

// value of Water Level (metres)
#define WL1 2
#define WL2 5
#define WL_MAX 6

class BridgeTask: public Task {

  bool* waterLevelCritical;
  Sonar* S;
  // ServoMotor* SM;
  // PotentiometerTask* Pot;
  Light* LC;
  Light* LB;
  // Button* B;
  LCD* lcd;
  enum { NORMAL, PRE_ALARM, ALARM, HUMAN_CONTROL } state;

  private:

  void setWaterLevelCritical(bool value);
  void changeToNormal();
  void changeToPreAlarm();
  void changeToAlarm();

  public:

  BridgeTask(int pinLedB, int pinLedC, int buttonPin, Sonar* sonar, bool* waterLevelCritical);
  void init(int period);
  void tick();

};

#endif
