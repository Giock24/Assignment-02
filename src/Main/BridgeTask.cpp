#include "BridgeTask.h"
#include "Arduino.h"

// value of Water Level to modify
#define WL1 4 
#define WL2 7
#define WL_MAX 10

const int normalPE = 25;
const int prealarmPE = 50;
const int alarmPE = 15;
const long blinkPeriod = 2000;

BridgeTask::BridgeTask(int pin1, int pin2, int buttonPin) {
  // this->S = sonar;
  // this->SM = servoMotor;
  // this->Pot = potentiometer;
  this->LC = new Led(pin1);
  this->LB = new Led(pin2);
  // this->B = new Button(buttonPin);
  // this-> LCD = new LCD();
}

void BridgeTask::init(int period) {
  Task::init(period);
  state = NORMAL;
}

void BridgeTask::tick() {
  switch (state) {
    case NORMAL:
      // if (sonar->getRiverLevel() > WL1 && sonar->getRiverLevel() < WL2)
      // lcd->showText("Pre-Alarm");
        state = PRE_ALARM;
        Task::init(prealarmPE);
      break;
    case PRE_ALARM:
      LC->blink(blinkPeriod);
      // if (sonar->getRiverLevel() > WL2 && sonar->getRiverLevel() <= WL_MAX)
        state = ALARM;
        Task::init(alarmPE);
        LB->switchOff();
        LC->switchOn();        
      break;
    case ALARM:
      //lcd->showText("Alarm -> " + (String) sonar->getRiverLevel());
      // if (sonar->getRiverLevel() < WL1)
        state = NORMAL;
        Task::init(normalPE);
        LB->switchOn();
        LC->switchOff();
       break;
    case HUMAN_CONTROL:
      // TODO
      break;
  }
}
