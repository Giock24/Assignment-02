#include "Task.h"
#include "Const.h"
#include "Led.h"

class BridgeTask: public Task {

  // Sonar* S;
  // ServoMotor* SM;
  // Potentiometer* Pot;
  Light* LC;
  Light* LB;
  // Button* B;
  // LCD* lcd;
  enum { NORMAL, PRE_ALARM, ALARM, HUMAN_CONTROL } state;

  public:

  BridgeTask(int pin1, int pin2);
  void init(int period);
  void tick();

};