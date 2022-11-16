#include "SmartLTask.h"
#include "Arduino.h"

#define PHOTORES_PIN A0
#define PIR_PIN 2

SmartLTask::SmartLTask(int pin) {
  this->pin = pin;
}

void SmartLTask::init(int period) {
  Task::init(period);
  this->led = new Led(pin);
  state = OFF;
  this->LS = new LightSensor(PHOTORES_PIN);
  this->PIR = new ProximitySensor(PIR_PIN);
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