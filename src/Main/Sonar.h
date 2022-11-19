#ifndef __SONAR__
#define __SONAR__

class Sonar {

  float currentLevel;
  int trigPin;
  int echoPin;

  public:

  Sonar(int trigPin, int echoPin);
  float getRiverLevel();

};

#endif
