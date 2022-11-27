#include "Button.h"
#include "Arduino.h"

Button::Button(int pin) {
  this->pin = pin;
}

bool Button::buttonIsPressed() {
  return digitalRead(this->pin) == HIGH;
}
