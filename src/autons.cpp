#include "robot-config.h"
#include "vex.h"
#include "PID.h"
#include "arm.h"
#include "functions.h"


using namespace vex;


void rightAuton() {
  //turnPID(90, 0.48,0,0);
\

//   
low.setVelocity(200, rpm);
  high.setVelocity(200, rpm);
  storage.setVelocity(200, rpm);
//Make turns 
  drivePID(4,0.3,0,0);
  turnPID(-90, 0.48,0,0);
//Storage
  Controller.Screen.print("Placing in storage"); 
  low.spin(forward);
  storage.spin(forward);
  
  drivePID(25,0.3,0,0);
  wait(0.5, sec);

  drivePID(2,0.3,0,0.1);


  wait(1, sec);

  drivePID(-2,0.3,0.1,0.1);

//Move to goal
  turnPID(-45,1,1,1);
  drivePID(8,0.3,0.1,0.1);
//Score blocks
  storage.spin(reverse);
  high.spin(reverse);
  low.spin(forward);
  wait(1, sec);
//Move a bit back
  drivePID(-1,0.3,0.1,0.1);

  //Stop all
  storage.stop();
  low.stop();
  high.stop();





  
  
}

void leftAuton() {
  

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

