#include "robot-config.h"
#include "vex.h"
#include "PID.h"
#include "arm.h"
#include "functions.h"

using namespace vex;


void rightAuton() {

  //drivePID(24, 0.1, 0, 0.01); 
  //turnPID(90, 0.3, 0 ,0); 
  RF.spin(forward, 100, percent);
  RM.spin(forward, 100, percent);
  RB.spin(forward, 100, percent);
  LF.spin(forward, 100, percent);
  LM.spin(forward, 100, percent);
  LB.spin(forward, 100, percent);
}

void leftAuton() {
  spinLeftDT(50);
  turnPID(90, 0.0, 0.001, 0.3);
  drivePID(6, 0.5, 0.003, 0.3);
  clamp();
}

void skillsAuton() {
  drivePID(12, 0.5, 0.003, 0.3);
  turnPID(90, 0.06, 0.001, 0.3);
  clamp();
  liftArm(30, 5);
  drivePID(-12, 0.5, 0.003, 0.3);
  turnPID(90, 0.06, 0.001, 0.3);
  drivePID(6, 0.5, 0.003, 0.3);
  clamp();
}
