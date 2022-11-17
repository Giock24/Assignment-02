#define CALIBRATION_TIME_SEC 10

#include "ProximitySensor.h"
#include "Arduino.h"

ProximitySensor::ProximitySensor(int pin) {
  this->pin = pin;
  this->detectedStatus = false;
  pinMode(pin, INPUT);
  this->calibratePIR();
}

void ProximitySensor::calibratePIR() {
  Serial.print("Calibrating sensor... ");
  for(int i = 0; i < CALIBRATION_TIME_SEC; i++){
    //Serial.print(".");
    delay(1000);
  }
}

bool ProximitySensor::isSomeoneDetected() {
  detectedStatus = digitalRead(pin);
  if (detectedStatus) {
    Serial.println("detected!");
  } else {
    Serial.println("no more detected.");
  }
  return detectedStatus;
}

void ProximitySensor::init(int period) {
  Task::init(period);
  state = NOT_DETECTED;
}

void ProximitySensor::tick() {
  switch(state) {
    case DETECTED:
      if (!this->isSomeoneDetected()) {
        state = NOT_DETECTED;
      }
      break;

    case NOT_DETECTED:
      if (this->isSomeoneDetected()) {
        state = DETECTED;
      }
      break;
  }
}