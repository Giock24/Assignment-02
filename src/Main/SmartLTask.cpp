#include "SmartLTask.h"

SmartLTask::SmartLTask(int pin) {
  this->pin = pin;
}

void SmartLTask::init(int period) {
  Task::init(period);
  led = new Led(pin);
  state = OFF;
}

void SmartLTask::tick() {
  switch(state) {
    case OFF:
      // if (isSomeoneDetected() && getIntensity()<Lmax)
      led->switchOn();
      state = ON;
      break;
    case ON:
      // if (getIntensity()>=Lmax)
      led->switchOff();
      state = OFF;

      // if (!isSomeoneDetected)
      state = TURNING_OFF;

      // if (waterLevelCritical) when in FSM bridge is in state = Alarm (WaterLevel BETWEEN WL2 And WLMAX)
      state = OFF;
      break;
    case TURNING_OFF:
      // if (isSomeoneDetected during T1)
      state = ON;
      // else
      state = OFF;
      break;
  }
}