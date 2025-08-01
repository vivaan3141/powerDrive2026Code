#include "robot-config.h"
#include "vex.h"
#include "PID.h"
#include "arm.h"
#include "functions.h"

using namespace vex;


void rightAuton() {
  

}

void leftAuton() {
  low.setVelocity(200, rpm);
  high.setVelocity(200, rpm);
  storage.setVelocity(200, rpm);
//Make turns 
  drivePID(8,1,1,1);
  turnPID(90, 1, 1, 1);
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

  //Turn
  turnPID(40,1,1,1);
  drivePID(36,1,1,1);

  //store
  Controller.Screen.print("Placing in storage"); 
  low.spin(forward);
  storage.spin(forward);
  drivePID(2,1,1,1);
  wait(1, sec);

//Turn and move to goal
  turnPID(-135,1,1,1);
  drivePID(8,1,1,1);

//Score low goal
  storage.spin(reverse);
  high.spin(reverse);
  low.spin(reverse);
  wait(1, sec);

  //Stop all
  storage.stop();
  low.stop();
  high.stop();
}


