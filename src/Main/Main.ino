#include "Scheduler.h"
#include "SmartLTask.h"

#define LED_PIN 13



Light* led;
Scheduler sched;

void setup(){
  Serial.begin(9600);
  sched.init(100);

  Task* t0 = new SmartLTask(10); // We have to choose the pin of smart light
  t0->init(100); // each 100ms is checked state of Smart Task

  sched.addTask(t0);
  
}

void loop(){
  sched.schedule();
};
