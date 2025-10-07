#include "robot-config.h"
#include "vex.h"
#include "PID.h"
#include "arm.h"
#include "functions.h"


using namespace vex;


void rightAuton() {
  //turnPID(90, 0.48,0,0);
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






  
  
}

void leftAuton() {
  

}

void skillsAuton() {
  

}


// Drivetrain.setDriveVelocity(30, percent);
//   // //drivePID(5,0.1,0.1,0.1);
//   // drivePID(24,0.1,0.1,0.1);

//   //    Drivetrain.setDriveVelocity(30, percent);
//   //    drivePID(24,0.1,0.1,0.12);



//   Drivetrain.setDriveVelocity(20, percent);
//   Drivetrain.setTurnVelocity(20, percent);
//   low.setVelocity(200, rpm);
//   high.setVelocity(200, rpm);
//   storage.setVelocity(200, rpm);
// //Make turns 
//   drivePID(4,0.3,0,0);
//   turnPID(0, 0.3,0,0);
//   drivePID(-30,0.3,0,0);
//   turnPID(20, 0.3,0,0);

//   Controller.Screen.print("Placing in storage"); 
//   low.spin(forward);
//   storage.spin(forward);
//   wait(1, sec);
//     drivePID(8,0.3,0,0);
//   wait(0.5, sec);

//   turnPID(-90, 0.3,0,0);    
//   wait(0.5, sec);

//   drivePID(4,0.1,0.1,0.12);
//     wait(0.6, sec);
//   drivePID(-4,0.1,0.1,0.12);
//     wait(0.5, sec);


// //Move to goal
//   turnPID(-45,0.1,0.1,0.1);
//   drivePID(5,0.1,0.1,0.1);
// //Score blocks
//   storage.spin(reverse);
//   high.spin(reverse);
//   low.spin(forward);
//   wait(1, sec);
// //Move a bit back
//   drivePID(-1,0.1,0.1,0.1);


//   //Stop all
//   storage.stop();
//   low.stop();
//   high.stop();

