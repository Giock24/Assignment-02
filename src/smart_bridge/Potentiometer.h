#ifndef __SONAR__
#define __SONAR__

class Potentiometer {

  int pin;
  int val;

  public:

  Potentiometer(int pin);
  int ptmAngle();

};

#endif