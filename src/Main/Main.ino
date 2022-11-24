#include "Scheduler.h"
#include "SmartLTask.h"
#include "BridgeTask.h"
#include "Const.h"
#include "Sonar.h"

Scheduler sched;
Sonar* sonar; // sonar must be shared for ServMotorTask

void setup(){
  bool waterLevelCritical = false;

  Serial.begin(9600);
  sonar = new Sonar(TRIG_PIN, ECHO_PIN);

  sched.init(100);

  Task* t0 = new PIRTask(PIR_PIN);
  t0->init(50);

  Task* t1 = new LightSensorTask(LIGHTSENSOR_PIN);
  t1->init(20);

  Task* t2 = new SmartLTask(LED_PIN, t0, t1, &waterLevelCritical); // We have to choose the pin of smart light
  t2->init(200); // each 100ms is checked state of Smart Task

  Task* t3 = new BridgeTask(LED_B, LED_C, BUTTON_PIN, sonar, &waterLevelCritical);
  t3->init(200);

  sched.addTask(t0);
  sched.addTask(t1);
  sched.addTask(t2);
  sched.addTask(t3);

}


void loop(){
  sched.schedule();
};
