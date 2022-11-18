#include "Scheduler.h"
#include "SmartLTask.h"
#include "Const.h"

Light* led;
Scheduler sched;

void setup(){
  Serial.begin(9600);
  sched.init(100);

  Task* t0 = new PIRTask(PIR_PIN);
  t0->init(50);

  Task* t1 = new LightSensorTask(LIGHTSENSOR_PIN);
  t1->init(20);

  Task* t2 = new SmartLTask(LED_PIN, t0, t1); // We have to choose the pin of smart light
  t2->init(200); // each 100ms is checked state of Smart Task

  sched.addTask(t0);
  sched.addTask(t1);
  sched.addTask(t2);

}

void loop(){
  sched.schedule();
};
