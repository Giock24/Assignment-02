#include "BridgeTask.h"
#include "Arduino.h"

const int normalPE = 25;
const int prealarmPE = 50;
const int alarmPE = 15;
const long blinkPeriod = 2000;

BridgeTask::BridgeTask(int pinLedB, int pinLedC, int buttonPin, Sonar* sonar, bool* waterLevelCritical) {
  this->S = sonar;
  // this->SM = servoMotor;
  // this->Pot = potentiometer;
  this->LB = new Led(pinLedB);
  this->LC = new Led(pinLedC);
  this->waterLevelCritical = waterLevelCritical;
  // this->B = new Button(buttonPin);
  // this-> LCD = new LCD();
}

void BridgeTask::init(int period) {
  Task::init(period);
  state = NORMAL;
}

void BridgeTask::tick() {
  float riverLevel = S->getRiverLevel();
  switch (state) {
    case NORMAL:
      Serial.println("Normal");
      if (riverLevel > WL2 && riverLevel < WL1) {
        this->changeToPreAlarm();
      }
      break;
    case PRE_ALARM:
      LC->blink(blinkPeriod);
      Serial.println("Pre-Alarm");
      if (riverLevel > WL_MAX && riverLevel <= WL2) {
        this->changeToAlarm();
      }
      if (riverLevel >= WL1) {
        this->changeToNormal();        
      }
      break;
    case ALARM:
      Serial.println("Alarm");
      //lcd->showText("Alarm -> " + (String) sonar->getRiverLevel());


      if (riverLevel >= WL1) {
        this->changeToNormal();
      }
       break;
    case HUMAN_CONTROL:
      // TODO
      break;
  }
}

void BridgeTask::setWaterLevelCritical(bool value) {
  *this->waterLevelCritical = value;
}

void BridgeTask::changeToNormal() {
  this->setWaterLevelCritical(false);
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
  this->setWaterLevelCritical(true);
  state = ALARM;
  Task::init(alarmPE);
  LB->switchOff();
  LC->switchOn();  
}
