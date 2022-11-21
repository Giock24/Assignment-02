#include "ServMotorTask.h"
#include "Arduino.h"

float const WL2 = 20.00;
float const WLMAX = 25.00;

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
  if(MySonar->getRiverLevel() > WL2 && MySonar->getRiverLevel() <= WLMAX){
    float difference = WLMAX - MySonar->getRiverLevel();
    int radious = map(difference, 0.01, 5.00, 1, 180 );
    return radious;
  }
  return 0;

  
}