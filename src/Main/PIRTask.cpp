#include "PIRTask.h"
#include "Arduino.h"
#include "Const.h"

PIRTask::PIRTask(int pin) {
  this->pin = pin;
  this->detectedStatus = false;
  pinMode(pin, INPUT);
  this->calibratePIR();
}

void PIRTask::calibratePIR() {
  Serial.print("Calibrating sensor... ");
  for(int i = 0; i < CALIBRATION_TIME_SEC; i++){
    //Serial.print(".");
    delay(1000);
  }
}

bool PIRTask::isSomeoneDetected() {
  detectedStatus = digitalRead(pin);
  if (detectedStatus) {
    Serial.println("detected!");
  } else {
    Serial.println("no more detected.");
  }
  return detectedStatus;
}

void PIRTask::init(int period) {
  Task::init(period);
  this->myPeriod = period;
  this->timeNotDetected = 0;
  state = NOT_DETECTED;
}

void PIRTask::tick() {
  switch(state) {
    case DETECTED:
      if (!this->isSomeoneDetected()) {
        state = NOT_DETECTED;
      }
      break;

    case NOT_DETECTED:
      this->timeNotDetected += this->myPeriod;

      if (this->isSomeoneDetected()) {
        this->timeNotDetected = 0;
        state = DETECTED;
      }
      break;
  }
}

// this method returns true when someone is detected between 0 and T1 seconds, else false.
bool PIRTask::isSomeoneDetectedT1() {
  return this->isSomeoneDetected() && (this->timeNotDetected >= 0 && this->timeNotDetected < T1);
}

enum PIRTask::PIRState PIRTask::getState() {
  return this->state;
}
