#include "Arduino.h"
#include "SonarTask.h"

const float vs = 331.45 + 0.62*20;//sound speed + temperature correction factor * degrees

SonarTask::SonarTask(int trigPin, int echoPin) {
  this->trigPin = trigPin;
  this->echoPin = echoPin;
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void SonarTask::init(int period) {
  Task::init(period);
}

void SonarTask::tick() {
  /* sending impulse */
  digitalWrite(this->trigPin, LOW);
  delayMicroseconds(3); 
  digitalWrite(this->trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(this->trigPin, LOW);

  /* receiving the eco */
  float tUS = pulseIn(this->echoPin, HIGH);
  float t = tUS / 1000.0 / 1000.0 / 2;
  this->currentLevel = t * vs;

  //Serial.println("water level -> "+ (String) this->currentLevel);
}

void SonarTask::normalPeriod(int period) {
  Task::init(period);
}

void SonarTask::preAlarmPeriod(int period) {
  Task::init(period);
}
void SonarTask::alarmPeriod(int period) {
  Task::init(period);
}

float SonarTask::getRiverLevel() {
  return this->currentLevel;
}