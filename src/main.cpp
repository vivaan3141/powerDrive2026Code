/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       katherinezeng                                             */
/*    Created:      5/27/2025, 10:30:19 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "robot-config.h"
#include "PID.h"
#include "autons.h"
#include "auton-selector.h"
#include "functions.h"

using namespace vex;

// A global instance of competition
competition Competition;


void pre_auton(void) {

  vexcodeInit();
  displayAutonSelector();
  // Start calibration.
InertialSensor.calibrate();
// Print that the Inertial Sensor is calibrating while
// waiting for it to finish calibrating.
low.setVelocity(200, rpm);
high.setVelocity(200, rpm);
while(InertialSensor.isCalibrating()){
    Brain.Screen.print("Inertial Calibrating");
    wait(5, sec);
    

}

  
}

void autonomous(void) {
  
  switch (getSelectedAuton()) {
    case 0:
      rightAuton();
      break;
    case 1:
      leftAuton();
      break;
    default:
      Brain.Screen.print("No valid auton selected!");
      break;
  }
 


}

void reverseIntake(){
  low.spin(reverse);
}

void intakeStorage(){
  Controller.Screen.print("Placing in storage"); 
  low.spin(forward);
  storage.spin(forward);
}

void storageOut(){
  Controller.Screen.print("Taking out of storage"); 
  storage.spin(reverse);
}
void middleGoal(){
  low.spin(forward);
  high.spin(reverse);
  Controller.Screen.print("Middle Goal");
}
void longGoal(){
  high.spin(forward); // Score long, moves all stages
  Controller.Screen.print("LONG GOAL");
}

// All released button functions


void reverseIntakeRELEASED(){
  low.stop();
}

void intakeStorageRELEASED(){ 
  low.stop();
  storage.stop();
}

void storageOutRELEASED(){
  storage.stop();
}
void middleGoalRELEASED(){
  low.stop();
  high.stop();

}
void longGoalRELEASED(){
  high.stop();
}



void usercontrol(void) {

    Controller.ButtonA.pressed(reverseIntake);
    Controller.ButtonL1.pressed(intakeStorage);
    Controller.ButtonL2.pressed(storageOut);
    Controller.ButtonR1.pressed(middleGoal);
    Controller.ButtonR2.pressed(longGoal);

    Controller.ButtonA.released(reverseIntakeRELEASED);
    Controller.ButtonL1.released(intakeStorageRELEASED);
    Controller.ButtonL2.released(storageOutRELEASED);
    Controller.ButtonR1.released(middleGoalRELEASED);
    Controller.ButtonR2.released(longGoalRELEASED);

  

  while (true) {
    // ========== DRIVE CONTROL ========== //

    double fwd = Controller.Axis3.position();
    double turn = Controller.Axis1.position();

    double leftPower  = fwd + turn;
    double rightPower = fwd - turn;

    spinLeftDT(leftPower * 0.7);
    spinRightDT(rightPower * 0.7);

    // low.setVelocity(200, rpm);

    
    



      // DO individual programming for  Intake, High, and Storage.
      
/*
    // ========== Button Controls ========== //
    if (Controller.ButtonA.pressing()) { // Left side front buttons
      low.setVelocity(200, rpm);
      high.setVelocity(200, rpm);
      Controller.Screen.print("REVERSE! ");
      low.spin(reverse);
      high.spin(forward); // descore all stages

    }else if (Controller.ButtonL1.pressing()) {
      low.setVelocity(200, rpm);
      high.setVelocity(200, rpm);
      storage.setVelocity(200, rpm);
      Controller.Screen.print("Placing in storage"); 

      low.spin(forward);
      storage.spin(forward);
    
    }else if (Controller.ButtonL2.pressing()) {
      low.setVelocity(200, rpm);
      high.setVelocity(200, rpm);
      storage.setVelocity(200, rpm);
      Controller.Screen.print("Taking out of storage"); 

      storage.spin(reverse);
    
    }else if (Controller.ButtonR1.pressing()) { // left side front buttons
      low.setVelocity(200, rpm);
      high.setVelocity(200, rpm);

      low.spin(forward);
      Controller.Screen.print("Middle Goal");

    } else if (Controller.ButtonR2.pressing()) {
      high.setVelocity(200, rpm);

      high.spin(reverse); // Score long, moves all stages
      Controller.Screen.print("LONG GOAL");

       // intake  open
    }else{
      low.stop();
      high.stop(); 
      Controller.Screen.print("POWER-DRIVE:13707X!");

    }
*/
    wait(20, msec);
  }
}


int main(){

  pre_auton();

  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  //Competition.test_auton();
  //Competition.test_driver();


  while (true) {
    wait(100, msec);
  }
}
