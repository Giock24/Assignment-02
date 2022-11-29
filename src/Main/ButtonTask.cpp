#include "ButtonTask.h"

ButtonTask::ButtonTask(Button* btn){
  this->btn = btn;
  this->oldstate = true;
  this->newstate = false;
}

void ButtonTask::init(int period) {
  Task::init(period);
}

void ButtonTask::tick(){
  bool readvalue = btn->buttonIsPressed();
  if(readvalue /*&& !oldstate*/) {
    delay(20);
  }
  oldstate = readvalue;

  /*if(btn->buttonIsPressed() && oldstate != newstate){
    delay(20);

    Serial.println("btnpressed");
  }*/
}

bool ButtonTask::wasPressed(){

  //oldstate = newstate;
  bool readvalue = btn->buttonIsPressed();
  if(readvalue /*&& !oldstate*/) {
    delay(20);
  }
  newstate = readvalue;

  return newstate != oldstate;

 /* if(newstate){
    newstate = false;
    return true;
  }
  return false;*/
}
