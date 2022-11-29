/*
 * This header contains all symbols and constants
 * that concerns the configuration of the system
 */

#ifndef __CONST__
#define __CONST__

// pins:
#define PIR_PIN 2
#define LED_PIN 3
#define LED_B 4 // GREEN LED
#define LED_C 5 // RED LED
#define BUTTON_PIN 7
#define TRIG_PIN 8
#define ECHO_PIN 9
#define SERVO_PIN 10
#define POT_PIN A1
#define LIGHTSENSOR_PIN A0

#define NORMAL_COND riverLevel >= WL1
#define PRE_ALARM_COND riverLevel > WL2 && riverLevel < WL1
#define ALARM_COND riverLevel >= WL_MAX && riverLevel <= WL2
#endif
