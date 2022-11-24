#ifndef __SMARTLTASK__
#define __SMARTLTASK__

#include "Task.h"
#include "Led.h"
#include "PIRTask.h"
#include "LightSensorTask.h"

class SmartLTask: public Task {

  PIRTask* PIR;
  Light* led;
  LightSensorTask* LS;
  bool* waterLevelCritical; //when in FSM bridge is in state = Alarm (WaterLevel betweeen WL2 and WLMAX)
  enum { ON, TURNING_OFF, OFF } state;

  public:

  SmartLTask(int pin, PIRTask* pir, LightSensorTask* lightSensor, bool* waterLevelCritical);
  void init(int period);
  void tick();

};

#endif