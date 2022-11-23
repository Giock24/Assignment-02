#include "ServMotorTask.h"
#include "Arduino.h"
#include "BridgeTask.h"

float difference = 0;

enum tipo (*example)();

ServMotorTask::ServMotorTask(ServoMotor* servo, Sonar* sonar){
  this->myservo = servo;
  this->mysonar = sonar;
}

void ServMotorTask::init(int period){
  Task::init(period);
  Vstate = CLOSE;
}

void ServMotorTask::tick(){
  switch(Vstate){
    case(CLOSE):
      if(/* BridgeTask.state == Alarm*/) {
        this->Vstate = OPEN;
        this->myservo.move(openingAngle());
      }

      break;
    case(OPEN):
      if(/* BridgeTask.state != Alarm*/){
        this->Vstate = CLOSE;
        this->myservo.move(0); // da provare, possibile che bisogna mettere 1 invece che 0 per come è implementato il metodo Servo.write().
      }
      else{
        this->myservo.move(openingAngle());
      }

      break;

  }
}

// Questo metodo ritorna l'angolo di apertura in base a quanto è alto il livello dell'acqua.
int ServMotorTask::openingAngle(){
  if(mysonar->getRiverLevel() > WL2 && mysonar->getRiverLevel() <= WL_MAX){
    float difference = WL_MAX - mysonar->getRiverLevel();
    int radious = map(difference, 0.01, 5.00, 1, 180 );
    return radious;
  }
  return 0;

  
}