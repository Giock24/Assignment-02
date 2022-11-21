#include "BridgeTask.h"
#include "Arduino.h"

const int normalPE = 25;
const int prealarmPE = 50;
const int alarmPE = 15;
const long blinkPeriod = 2000;

BridgeTask::BridgeTask(int pin1, int pin2, int buttonPin, Sonar* sonar) {
  this->S = sonar;
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
      if (S->getRiverLevel() > WL1 && S->getRiverLevel() < WL2) {
        this->changeToPreAlarm();
      }
      break;
    case PRE_ALARM:
      LC->blink(blinkPeriod);
      if (S->getRiverLevel() > WL2 && S->getRiverLevel() <= WL_MAX) {
        this->changeToPreAlarm();
      }
      if (S->getRiverLevel() < WL1) {
        this->changeToNormal();        
      }
      break;
    case ALARM:
      //lcd->showText("Alarm -> " + (String) sonar->getRiverLevel());
      if (S->getRiverLevel() < WL1) {
        this->changeToNormal();
      }
       break;
    case HUMAN_CONTROL:
      // TODO
      break;
  }
}

void BridgeTask::changeToNormal() {
  state = NORMAL;
  Task::init(normalPE);
  LB->switchOn();
  LC->switchOff();  
}

void BridgeTask::changeToPreAlarm() {
  // lcd->showText("Pre-Alarm");
  state = PRE_ALARM;
  Task::init(prealarmPE);
}

void BridgeTask::changeToAlarm() {
  state = ALARM;
  Task::init(alarmPE);
  LB->switchOff();
  LC->switchOn();  
}
