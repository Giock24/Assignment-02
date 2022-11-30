#include "Button.h"
#include "Arduino.h"

Button::Button(int pin) {
  this->pin = pin;
  pinMode(this->pin, INPUT);
}

bool Button::buttonIsPressed() {
  return digitalRead(this->pin) == HIGH; //  TODO return digitalRead(this->pin) != HIGH;
}
