#include "Sonar.h"
#include "Arduino.h"

const float vs = 331.45 + 0.62*20;

Sonar::Sonar(int trigPin, int echoPin) {
  this->trigPin = trigPin;
  this->echoPin = echoPin;
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

float Sonar::getRiverLevel() {
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
  Serial.println("water level -> "+ (String) this->currentLevel);
  return this->currentLevel;
}