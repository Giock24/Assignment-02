#include "ServMotorTask.h"
#include "Arduino.h"
#include "BridgeTask.h"

// float difference = 0;

ServMotorTask::ServMotorTask(ServoMotor* servo, SonarTask* sonar){
  this->myservo = servo;
  this->mysonar = sonar;
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
        this->myservo->move(openingAngle());
      }

      break;
    case(OPEN):
      if(!checkWater()){
        this->Vstate = CLOSE;
        this->myservo->move(0); // da provare, possibile che bisogna mettere 1 invece che 0 per come è implementato il metodo Servo.write().
      }
      else{
        this->myservo->move(openingAngle());
      }

      break;

  }
}

// Questo metodo ritorna l'angolo di apertura in base a quanto è alto il livello dell'acqua.
int ServMotorTask::openingAngle(){
  if(checkWater()){
    // float difference = WL_MAX - mysonar->getRiverLevel();
    int radious = map(mysonar->getRiverLevel()*100, 0, 5, 180, 1 );
    return radious;
  }
  return 0;

  
}