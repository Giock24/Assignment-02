#ifndef __BRIDGETASK__
#define __BRIDGETASK__

#include "Task.h"
#include "Const.h"
#include "Led.h"
#include "LCD.h"
#include "SonarTask.h"
#include "ServMotorTask.h"

// value of Water Level (metres)
#define WL1 0.15
#define WL2 0.05
#define WL_MAX 0.00

class BridgeTask: public Task {

  bool* waterLevelCritical;
  SonarTask* S;
  ServMotorTask* SM;
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

  BridgeTask(int pinLedB, int pinLedC, int buttonPin, SonarTask* sonar, bool* waterLevelCritical, ServMotorTask* servo);
  void init(int period);
  void tick();

};

#endif
