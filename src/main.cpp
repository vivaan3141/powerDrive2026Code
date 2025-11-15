/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Vivaan Gupta                                              */
/*    Created:      5/27/2025, 10:30:19 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "robot-config.h"
#include "PID.h"
#include "autons.cpp"
#include "auton-selector.h"
#include "functions.h"
#include <iostream>
using namespace vex;

// A global instance of competition
competition Competition;
bool stateLoader=false;

void autonCodes(int x) {
  if (x==1){
    Loader.set(true);
    // Auton Port 1
    // Scores 1 block on Middle goal and faces optimal position
    // Setup
    low.setVelocity(200, rpm);
    high.setVelocity(200, rpm);
    storage.setVelocity(200, rpm);

    drivePID(7,0.1,0.05,-0.1);
    Drivetrain.turnToHeading(90,degrees);
    low.spin(forward);
    storage.spin(forward);

    //Make turns 
    //drivePID(30.5,0.1,0.05,-0.1);
    Drivetrain.setDriveVelocity(10, percent);
    Drivetrain.driveFor(31,inches);
    Drivetrain.turnToHeading(130,degrees);
    
    wait(1, sec);
    Drivetrain.setDriveVelocity(10, percent);

    Drivetrain.driveFor(17,inches);
    wait(0.5, sec);

    high.spin(reverse);
    storage.spin(reverse);
    low.spin(forward);
    wait(5, sec);
    high.stop();
    storage.stop();
    low.stop();
    // drivePID(-15,0.3,0.05,0.1);
    // turnPID(45, 0.5,0.05,0.1);
    

  } else if (x==2){
    // Low Goal Match
    low.setVelocity(200, rpm);
    high.setVelocity(200, rpm);
    storage.setVelocity(200, rpm);
    Drivetrain.setDriveVelocity(80, percent);

    drivePID(7,0.1,0.05,-0.1);
    Drivetrain.turnToHeading(-90,degrees);
    low.spin(forward);
    storage.spin(forward);

    Drivetrain.setDriveVelocity(10, percent);
    Drivetrain.driveFor(31,inches);
    Drivetrain.turnToHeading(-130,degrees);

    Drivetrain.setDriveVelocity(10, percent);
    Drivetrain.setDriveVelocity(80, percent);
    Drivetrain.driveFor(17,inches);
    wait(0.5, sec);
    high.spin(reverse);
    storage.spin(reverse);
    low.spin(reverse);
    wait(5, sec);
    high.stop();
    storage.stop();
    low.stop();
    low.setVelocity(200, rpm);
  } else if (x==3){
    // Skills Auton Port 3
    //Scores 1 block on long goal and parks
    //Setup:
    Drivetrain.setDriveVelocity(60, percent);
    low.setVelocity(200, rpm);
    high.setVelocity(200, rpm);
    storage.setVelocity(200, rpm);

    drivePID(30,0.3,0.05,0.1);
    turnPID(-90, 0.48,0,0);
    
    //Make turns 
    wait(1, sec);

    drivePID(23,0.3,0.05,0.1);

    wait(0.5, sec);

    high.spin(forward);
    storage.spin(reverse);
    low.spin(forward);
    wait(3, sec);
    high.stop();
    storage.stop();
    low.stop();

    drivePID(-10,0.3,0.05,0.1);
    turnPID(90, 0.5,0.05,0.1);
    drivePID(-47,0.3,0.05,0.1);
    turnPID(-90, 0.5,0.05,0.1);

    drivePID(-20,0.3,0.05,0.1);
    wait(0.5, sec);
    // drivePID(1,0.3,0.05,0.1);
    // drivePID(-3,0.3,0.05,0.1);
  }else if (x==4){
    Loader.set(true);
    Drivetrain.setDriveVelocity(10, percent);
    low.setVelocity(200, rpm);
    high.setVelocity(200, rpm);
    storage.setVelocity(200, rpm);
//A
    //drivePID(26.5,0.1,0.05,0.1);
    Drivetrain.driveFor(33,inches);
    Drivetrain.turnToHeading(-90, degrees);
    Loader.set(false);
    wait(1, sec);
    storage.spin(forward);
    Drivetrain.setDriveVelocity(10, percent);
    Drivetrain.driveFor(10,inches);
//Takes out
    low.spin(forward);
    Drivetrain.driveFor(2,inches);
    Drivetrain.driveFor(-2,inches);
    wait(0.1, sec);
    Drivetrain.driveFor(2,inches);
    Drivetrain.driveFor(-2,inches);
    wait(0.1, sec);
    Drivetrain.driveFor(2,inches);
    Drivetrain.driveFor(-2,inches);
    wait(0.3, sec);
    Drivetrain.driveFor(2,inches);
    Drivetrain.driveFor(-2,inches);
    wait(0.3, sec);
    Drivetrain.driveFor(2,inches);
    Drivetrain.driveFor(-2,inches);
    wait(0.3, sec);
    Drivetrain.driveFor(2,inches);
    Drivetrain.driveFor(-2,inches);
    wait(0.3, sec);
    Drivetrain.driveFor(2,inches);
    Drivetrain.driveFor(-2,inches);
    wait(0.3, sec);
    Drivetrain.driveFor(2,inches);
    Drivetrain.driveFor(-2,inches);
    wait(0.3, sec);
    Drivetrain.driveFor(2,inches);
    Drivetrain.driveFor(-2,inches);
    wait(0.3, sec);
    storage.stop();
//d
    Drivetrain.driveFor(-6,inches);
    Loader.set(true);
    low.stop();

    // GO to long Goal  1
    Drivetrain.turnToHeading(87, degrees);
    Drivetrain.driveFor(20,inches);
    
  //Scores in goal 1
    high.spin(forward);
    storage.spin(reverse);
    low.spin(forward);
    wait(7, sec);
    high.stop();
    storage.stop();
    low.stop();

    Drivetrain.driveFor(-9,inches);
    Drivetrain.turnToHeading(180, degrees);
    
    Drivetrain.driveFor(52,inches);
    Drivetrain.setDriveVelocity(20, percent);
    Drivetrain.turnToHeading(90, degrees);
    Drivetrain.driveFor(-22,inches);
    wait(1, sec);
    Drivetrain.driveFor(-10,inches);

  }else if(x==5){
    Drivetrain.setDriveVelocity(60, percent);
    low.setVelocity(200, rpm);
    high.setVelocity(200, rpm);
    storage.setVelocity(200, rpm);

    drivePID(30,0.3,0.05,0.1);
    turnPID(-90, 0.48,0,0);
    
    //Make turns 
    wait(1, sec);

    drivePID(23,0.3,0.05,0.1);

    wait(0.5, sec);

    high.spin(forward);
    storage.spin(reverse);
    low.spin(forward);
    wait(3, sec);
    high.stop();
    storage.stop();
    low.stop();
  }
}

void pre_auton(void) {
  Loader.set(true);
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

void autonomous() {
  Drivetrain.setStopping(hold);
  autonCodes(4);
}
 
void reverseIntake(){
  low.spin(reverse);
  high.spin(reverse);

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
  low.spin(forward);

  Controller.Screen.print("LONG GOAL");
}
void loadOut(){
  Controller.Screen.print("Loading"); 
  Loader.set(true);
  

}
void loadRest(){
  Loader.set(false);
  
}


void reverseIntakeRELEASED(){
  low.stop();
  high.stop();

}

void intakeStorageRELEASED(){ 
  low.stop();
  storage.stop();
  high.stop();
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
  low.stop();
}
void load(){
  if (stateLoader==true){
    loadOut();
    stateLoader=false; // Happy :)
  }else {
    loadRest();
    stateLoader=true;
  }
}

void usercontrol(void) {
  high.setVelocity(200, rpm);
  low.setVelocity(200, rpm);
  storage.setVelocity(200, rpm);

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

// Pneumatics
  Controller.ButtonUp.pressed(load);

  while (true) {
    // ========== DRIVE CONTROL ========== //
    Drivetrain.setStopping(coast);

    double fwd = Controller.Axis3.position();
    double turn = Controller.Axis1.position();

    double leftPower  = fwd + turn;
    double rightPower = fwd - turn;

    spinLeftDT(leftPower * 0.7);
    spinRightDT(rightPower * 0.7);

  
    wait(20, msec);
  }
}

int main(){

  pre_auton();
  Loader.set(true);

  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  
  //Competition.test_auton();
  //Competition.test_driver();
  
  while (true) {
    wait(100, msec);
  }
}
