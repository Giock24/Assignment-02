#ifndef __SONARTASK__
#define __SONARTASK__

#include "Task.h"

class SonarTask: public Task {

  float currentLevel;
  int trigPin;
  int echoPin;

  public:

  SonarTask(int trigPin, int echoPin);
  void init(int period);
  void tick();
  void normalPeriod(int period);
  void preAlarmPeriod(int period);
  void alarmPeriod(int period);
  float getRiverLevel();

};

#endif
