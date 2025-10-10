#include "robot-config.h"
#include "vex.h"
#include "PID.h"
#include "functions.h"


using namespace vex;


void auton(int x) {
  if (x==1){
    turnPID(90, 0.48,0,0);
  Drivetrain.setDriveVelocity(60, percent);

//   
low.setVelocity(200, rpm);
  high.setVelocity(200, rpm);
  storage.setVelocity(200, rpm);
//Make turns 
  drivePID(8.5,0.3,0.05,0.1);
  turnPID(-90, 0.5,0.05,0.1);
//Storage
  // Controller.Screen.print("Placing in storage"); 
  // low.spin(reverse);
  // storage.spin(forward);
  
  // Drivetrain.setDriveVelocity(10, percent);
  drivePID(31,0.3,0.05,0.1);

  wait(0.5, sec);

//Move to goal
  Drivetrain.setDriveVelocity(40, percent);

  turnPID(-60,0.5,0.05,0.15);
  drivePID(14.3,0.3,0.05,0.15);
//Score blocks
  high.spin(reverse);
  storage.spin(reverse);

  low.spin(forward);
  wait(1, sec);
  } else if (x==2){
    turnPID(90, 0.48,0,0);
  Drivetrain.setDriveVelocity(60, percent);

//   
low.setVelocity(200, rpm);
  high.setVelocity(200, rpm);
  storage.setVelocity(200, rpm);
//Make turns 
  drivePID(8.5,0.3,0.05,0.1);
  turnPID(-90, 0.5,0.05,0.1);
//Storage
  // Controller.Screen.print("Placing in storage"); 
  // low.spin(reverse);
  // storage.spin(forward);
  
  // Drivetrain.setDriveVelocity(10, percent);
  drivePID(31,0.3,0.05,0.1);

  wait(0.5, sec);

//Move to goal
  Drivetrain.setDriveVelocity(40, percent);

  turnPID(-60,0.5,0.05,0.15);
  drivePID(14.3,0.3,0.05,0.15);
//Score blocks
  high.spin(reverse);
  storage.spin(reverse);

  low.spin(forward);
  wait(1, sec);
  }else{
    //skills auton :)
  }


}

