#include "ButtonTask.h"

ButtonTask::ButtonTask(Button* btn){
  this->btn = btn;
}

void ButtonTask::init(int period) {
  Task::init(period);
  bstate = false;
}

void ButtonTask::tick(){
  if(btn->buttonIsPressed()){
    delay(20);
    bstate = true;
  }
}

bool ButtonTask::buttonWasPressed(){
  bstate = false;
  return true;
}
