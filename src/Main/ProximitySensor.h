#ifndef __PROXIMITYSENSOR__
#define __PROXIMITYSENSOR__

class ProximitySensor {

  int pin;
  bool detectedStatus;

  private:

  void calibratePIR();

  public:

  ProximitySensor(int pin, const mode);
  bool isSomeoneDetected();

}