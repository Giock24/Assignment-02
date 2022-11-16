#define CALIBRATION_TIME_SEC 10

#include "ProximitySensor.h"
#include "Arduino.h"

ProximitySensor::ProximitySensor(int pin, const mode) {
  this->pin = pin;
  this->detectedStatus = false;
  pinMode(pin, INPUT)
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
  return detectedStatus;
}