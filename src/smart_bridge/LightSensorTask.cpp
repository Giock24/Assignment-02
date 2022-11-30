#define FREQ 5
#define PERIOD 1000/FREQ

#include "LightSensorTask.h"
#include "Arduino.h"

LightSensorTask::LightSensorTask(int pin) {
  this->pin = pin;
  pinMode(pin, INPUT);
}

void LightSensorTask::init(int period) {
  Task::init(period);
}

void LightSensorTask::tick() {
  int value = analogRead(pin);
  valueInVolt = ((double) value) * 5/1024;
  //Serial.println(String(value) + " -> in volt: " + valueInVolt );
}

double LightSensorTask::getIntensity() {
  return valueInVolt;
}
