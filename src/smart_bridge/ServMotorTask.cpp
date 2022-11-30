#include "ServMotorTask.h"
#include "Arduino.h"
#include "BridgeTask.h"

ServMotorTask::ServMotorTask(ServoMotor* servo, SonarTask* sonar){
  this->myservo = servo;
  this->mysonar = sonar;
  this->prevValue = 0;
}

bool ServMotorTask::checkWater(){
  return mysonar->getRiverLevel() > WL_MAX && mysonar->getRiverLevel() <= WL2;
}

void ServMotorTask::init(int period){
  Task::init(period);
  Vstate = CLOSE;
}

void ServMotorTask::tick(){
  switch(Vstate){
    case(CLOSE):
      if(checkWater()) {
        this->Vstate = OPEN;
        this->move(openingAngle());
      }
      break;
    case(OPEN):
      if(!checkWater()){
        this->Vstate = CLOSE;
        this->move(0);
      }
      else{
        this->move(openingAngle());
      }
      break;
    default:
      break;
  }
}

// Questo metodo ritorna l'angolo di apertura in base a quanto è alto il livello dell'acqua.
int ServMotorTask::openingAngle(){
  if(checkWater()){
    int radious = map(mysonar->getRiverLevel()*100, 0, WL2*100, 180, 0 );
    return radious;
  }
  return 0;
}

void ServMotorTask::move(int angle){
  if(prevValue != angle){
    myservo->move(angle);
    prevValue = angle;
  }
}

void ServMotorTask::alterState(){
  if(Vstate != MANUAL_CONTROL){
    Vstate = MANUAL_CONTROL;
    //Serial.println("Now in human control");
  }else{
    Vstate = checkWater() ? OPEN : CLOSE;
    //Serial.println("Now in automatic control");
  }
}
