#include "Scheduler.h"
#include "SmartLTask.h"
#include "BridgeTask.h"
#include "SonarTask.h"
#include "Const.h"
#include "ServoMotor.h"
#include "ServMotorTask.h"

Scheduler sched;
ServoMotor* servo;

void setup() {
  bool waterLevelCritical = false;
  Serial.begin(9600);

  servo = new ServoMotor(SERVO_PIN);
  
  sched.init(100);
  
  Task* sonar = new SonarTask(TRIG_PIN, ECHO_PIN); // sonar must be shared for ServMotorTask
  sonar->init(25);
  sched.addTask(sonar);
  
  Task* t0 = new PIRTask(PIR_PIN);
  t0->init(50);
  sched.addTask(t0);

  Task* t1 = new LightSensorTask(LIGHTSENSOR_PIN);
  t1->init(25);
  sched.addTask(t1);

  Task* t2 = new SmartLTask(LED_PIN, t0, t1, &waterLevelCritical); // We have to choose the pin of smart light
  t2->init(200); // each 100ms is checked state of Smart Task
  sched.addTask(t2);
  
  Task* t3 = new ServMotorTask(servo, sonar);
  t3->init(200);
  sched.addTask(t3); // ServoMotorTask
  
  Task* t4 = new BridgeTask(LED_B, LED_C, BUTTON_PIN, sonar, &waterLevelCritical, t3);
  t4->init(200);
  sched.addTask(t4);
  
}

void loop(){
  sched.schedule();
};
