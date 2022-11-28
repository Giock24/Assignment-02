#include "Scheduler.h"
#include "SmartLTask.h"
#include "BridgeTask.h"
#include "SonarTask.h"
#include "Const.h"
#include "ServoMotor.h"
#include "ServMotorTask.h"
#include "Button.h"
#include "ButtonTask.h"

Scheduler sched;
ServoMotor* servo;
Button* btn;

void setup() {
  bool waterLevelCritical = false;
  Serial.begin(9600);

  servo = new ServoMotor(SERVO_PIN);
  btn = new Button(BUTTON_PIN);

  sched.init(100);
  
  Task* sonar = new SonarTask(TRIG_PIN, ECHO_PIN); // sonar must be shared for ServMotorTask
  sonar->init(25);
  
  Task* t0 = new PIRTask(PIR_PIN);
  t0->init(50);

  Task* t1 = new LightSensorTask(LIGHTSENSOR_PIN);
  t1->init(25);

  Task* t2 = new SmartLTask(LED_PIN, t0, t1, &waterLevelCritical); // We have to choose the pin of smart light
  t2->init(200); // each 100ms is checked state of Smart Task
  
  Task* t3 = new ServMotorTask(servo, sonar);
  t3->init(180);

  Task* t4 = new ButtonTask(btn);
  t4->init(10);
  
  Task* t5 = new BridgeTask(LED_B, LED_C, sonar, &waterLevelCritical, t3, POT_PIN, t4);
  t5->init(180);

  sched.addTask(sonar);
  sched.addTask(t0);
  sched.addTask(t1);
  sched.addTask(t2);
  sched.addTask(t3); // ServoMotorTask
  sched.addTask(t4);
  sched.addTask(t5);
  
}

void loop(){
  sched.schedule();
};
