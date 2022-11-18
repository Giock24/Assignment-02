/*
 * This header contains all symbols and constants
 * that concerns the configuration of the system
 */

#ifndef __CONST__
#define __CONST__

// pins:
#define LED_PIN 10
#define PIR_PIN 2
#define LIGHTSENSOR_PIN A0

// const for time and other stuffs:
// Scheduler.cpp
#define MAX_TASKS 20

// PIRTask.cpp
#define CALIBRATION_TIME_SEC 10
#define T1 3 // max time in which nobody has been detected

#endif
