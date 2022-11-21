#include "ServMotorTask.h"
#include "Arduino.h"
#include "BridgeTask.h"

ServMotorTask::ServMotorTask(int pin, Sonar* sonar){
  this->pin = pin;
  this->MySonar = sonar;
}

void ServMotorTask::init(int period){
  Task::init(period);
  Vstate = CLOSE;
}

void ServMotorTask::tick(){
  switch(Vstate){
    case(CLOSE):

      break;
    case(OPEN):

      break;

  }
}

int ServMotorTask::GetRadious(){
  if(MySonar->getRiverLevel() > WL2 && MySonar->getRiverLevel() <= WL_MAX){
    float difference = WL_MAX - MySonar->getRiverLevel();
    int radious = map(difference, 0.01, 5.00, 1, 180 );
    return radious;
  }
  return 0;

  
}