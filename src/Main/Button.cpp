#include "Button.h"
#include "Arduino.h"
#include <EnableInterrupt.h>

void buttonPushed() {
  // TODO
}

Button::Button(int pin) {
  this->pin = pin;
  enableInterrupt(this->pin, buttonPushed, RISING);
}

bool Button::buttonIsPressed() {
  return digitalRead(this->pin) == HIGH;
}
