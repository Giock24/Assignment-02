#include "BridgeTask.h"
#include "Arduino.h"

const int normalPE = 54;
const int prealarmPE = 36;
const int alarmPE = 18;
const long blinkPeriod = 2000;

BridgeTask::BridgeTask(int pinLedB, int pinLedC, int buttonPin, SonarTask* sonar, bool* waterLevelCritical, ServMotorTask* servo) {
  this->S = sonar;
  this->SM = servo;
  // this->Pot = potentiometer;
  this->LB = new Led(pinLedB);
  this->LC = new Led(pinLedC);
  this->waterLevelCritical = waterLevelCritical;
  // this->B = new Button(buttonPin);
  this->lcd = new LCD();
}

void BridgeTask::init(int period) {
  Task::init(period);
  lcd->clear();
  lcd->write(1, 1, "State: ");
  lcd->write(2, 1, "Level: ");
  lcd->turnOff();
  LB->switchOn();
  state = NORMAL;
}

void BridgeTask::tick() {
  char riverLevelString[6];// Buffer big enough for 5-character float

  float riverLevel = S->getRiverLevel();
  dtostrf((double) riverLevel, 5, 2, riverLevelString);

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
      lcd->write(2, 8, (char*) riverLevelString);
      if (riverLevel >= WL_MAX && riverLevel <= WL2) {
        this->changeToAlarm();
      }
      if (riverLevel >= WL1) {
        this->changeToNormal();        
      }
      break;
    case ALARM:
      Serial.println("Alarm");
      lcd->write(2, 8, (char*) riverLevelString);

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
  //S->normalPeriod(normalPE);
  Task::init(normalPE);
  LB->switchOn();
  LC->switchOff();
  lcd->clear(2, 8, 5);
  lcd->turnOff();  
}

void BridgeTask::changeToPreAlarm() {
  state = PRE_ALARM;
  //S->preAlarmPeriod(prealarmPE);
  Task::init(prealarmPE);
  lcd->turnOn();
  lcd->write(1, 8, "Pre-Alarm");
}

void BridgeTask::changeToAlarm() {
  this->setWaterLevelCritical(true);
  state = ALARM;
  //S->alarmPeriod(alarmPE);
  Task::init(alarmPE);
  LB->switchOff();
  LC->switchOn();
  lcd->clear(1, 8, 9);
  lcd->write(1, 8, "Alarm");
}
