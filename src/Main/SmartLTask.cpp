#include "SmartLTask.h"
#include "LightSensorTask.h"
#include "Arduino.h"

#define INHIBIT_LS 0

const double Lmax = 4.0;

SmartLTask::SmartLTask(int ledPin, PIRTask* pir, LightSensorTask* lightSensor, bool* waterLevelCritical) {
  this->PIR = pir;
  this->led = new Led(ledPin);
  this->LS = lightSensor;
  this->waterLevelCritical = waterLevelCritical;
}

void SmartLTask::init(int period) {
  Task::init(period);
  state = OFF;
}

void SmartLTask::tick() {
  switch(state) {
    case OFF:
      if (PIR->isSomeoneDetected() && (INHIBIT_LS || LS->getIntensity() < Lmax) && !*waterLevelCritical) {
        led->switchOn();
        state = ON;
      }

      break;
    case ON:
      if (*waterLevelCritical || (LS->getIntensity() >= Lmax && !INHIBIT_LS)) {
        led->switchOff();
        state = OFF;
      } else if (!PIR->isSomeoneDetected()) {
        state = TURNING_OFF;
      }
      break;
    case TURNING_OFF:
      if (PIR->isSomeoneDetectedT1()) {
        state = ON;
      } else {
        led->switchOff();
        state = OFF;
      }
      break;
  }
}
