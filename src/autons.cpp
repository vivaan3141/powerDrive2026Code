#include "robot-config.h"
#include "vex.h"
#include "PID.h"
#include "arm.h"
#include "functions.h"

using namespace vex;


void rightAuton() {
  low.setVelocity(200, rpm);
  high.setVelocity(200, rpm);
  storage.setVelocity(200, rpm);
//Make turns intertial
  drivePID(8,1,1,1);
  turnPID(90, 2, 0, 0);
  drivePID(15,1,1,1);
//Storage
  Controller.Screen.print("Placing in storage"); 
  low.spin(forward);
  storage.spin(forward);
  drivePID(2,1,1,1);

  wait(1, sec);
//Move to goal
  turnPID(45,1,1,1);
  drivePID(8,1,1,1);
//Score blocks
  storage.spin(reverse);
  high.spin(reverse);
  low.spin(forward);
  wait(1, sec);
//Move a bit back
  drivePID(-1,1,1,1);
  storage.stop();
  low.stop();
  high.stop();

  






}

void leftAuton() {
  turnPID(90, 2, 0, 0);
}


