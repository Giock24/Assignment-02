#include "BridgeTask.h"
#include "Arduino.h"

const int normalPE = 75;
const int prealarmPE = 50;
const int alarmPE = 25;
const long blinkPeriod = 2000;

BridgeTask::BridgeTask(int pinLedB, int pinLedC, SonarTask* sonar, bool* waterLevelCritical, ServMotorTask* servo, int ptmPin, ButtonTask* btnTask) {
  this->S = sonar;
  this->SM = servo;
  this->LB = new Led(pinLedB);
  this->LC = new Led(pinLedC);
  this->waterLevelCritical = waterLevelCritical;
  this->Pot = new Potentiometer(ptmPin);
  this->lcd = new LCD();
  this->B = btnTask;
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
  char actualDegree[5];

  float riverLevel = S->getRiverLevel();
  dtostrf((double) riverLevel, 5, 2, riverLevelString);
  String degree = "hello";
  //degree.toCharArray(char *buf, unsigned int bufsize)

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
      String(SM->openingAngle()).toCharArray(actualDegree , 5);
    
      Serial.println("Alarm");
      lcd->clear(3, 10, 4);
      lcd->write(2, 8, (char*) riverLevelString);
      lcd->write(3, 10, (char*) actualDegree);

      if (riverLevel > WL2 && riverLevel < WL1) {
        this->changeToPreAlarm();
      }
      if (riverLevel >= WL1) {
        this->changeToNormal();
      }
      if(false){ // B->WasPressed() == true
        Serial.println("HUMAN CONTROL ACTIVATED!");
        state = HUMAN_CONTROL;
        SM->alterState();
      }
      break;
    case HUMAN_CONTROL:
      SM->move(Pot->ptmAngle());
      if(HUMAN_CONTROL_COND){ // B->WasPressed() == true
        SM->alterState();
        NORMAL_COND ? this->changeToNormal() : PRE_ALARM_COND ? this->changeToPreAlarm() : this->changeToAlarm();
      }
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
  lcd->clear(2, 8, 6);
  lcd->turnOff();  
}

void BridgeTask::changeToPreAlarm() {
  state = PRE_ALARM;
  //S->preAlarmPeriod(prealarmPE);
  Task::init(prealarmPE);
  lcd->turnOn();
  lcd->write(1, 8, "Pre-Alarm");
  lcd->clear(3, 1, 13);
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
  lcd->write(3, 1, "Degrees: ");
}
