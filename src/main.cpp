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
#include "functions.h"
#include <iostream>

using namespace vex;

competition Competition;
bool stateLoader=false;
bool stateDescore=false;


void autonCodes(int x) {
  Brain.Screen.print("Auton type");
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
    
    Drivetrain.driveFor(17.7,inches);
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
    Drivetrain.setDriveVelocity(10, percent);
    Drivetrain.driveFor(16.1,inches);
    wait(0.5, sec);
    high.spin(reverse);
    storage.spin(reverse);
    low.spin(reverse);
    wait(5, sec);
    high.stop();
    storage.stop();
    low.stop();
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
    Drivetrain.setDriveVelocity(10, percent);
    low.setVelocity(200, rpm);
    high.setVelocity(200, rpm);
    storage.setVelocity(200, rpm);

    Drivetrain.driveFor(10,inches);

  }else if(x==6){
    //Descore Test
    Descore.set(true);
  Brain.Screen.print("Descore True ");
  task::sleep(2000);
  Descore.set(false);
  Brain.Screen.print("Descore False ");
  task::sleep(2000);
  Descore.set(true);
  Brain.Screen.print("Descore True ");
  }
}

// Pre-Autonomous

void pre_auton(void) {
  Loader.set(true);
  Descore.set(true);
  Brain.Screen.print("Descore True ");
  task::sleep(2000);
  Descore.set(false);
  Brain.Screen.print("Descore False");
  task::sleep(2000);
  Descore.set(true);
  Brain.Screen.print("Descore True ");

  vexcodeInit();
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
// USER CONTROLS

void autonomous() {
  Drivetrain.setStopping(hold);
  autonCodes(6);
}
 
void reverseIntake(){
  low.spin(reverse);
  high.spin(reverse);
Controller.Screen.clearLine();

}

void intakeStorage(){
  Controller.Screen.print("Placing in storage"); 
  low.spin(forward);
  storage.spin(forward);
  Controller.Screen.clearLine();

}

void storageOut(){
  Controller.Screen.clearLine();

  Controller.Screen.print("Taking out of storage"); 
  storage.spin(reverse);
  
}
void middleGoal(){
  Controller.Screen.clearLine();

  low.spin(forward);
  high.spin(reverse);
  Controller.Screen.print("Middle Goal");
}
void longGoal(){
  Controller.Screen.clearLine();

  high.spin(forward); // Score long, moves all stages
  low.spin(forward);

  Controller.Screen.print("LONG GOAL");
}
void loadOut(){
  Controller.Screen.clearLine();

  Controller.Screen.print("Loading"); 
  Loader.set(true);
}

void loadRest(){
  Controller.Screen.clearLine();

  Loader.set(false);
}

void descoreOut(){
  Controller.Screen.clearLine();

  Descore.set(true);
}

void descoreIn(){
  Controller.Screen.clearLine();

  Descore.set(false);
}
void reverseIntakeRELEASED(){
  Controller.Screen.clearLine();

  low.stop();
  high.stop();
}

void intakeStorageRELEASED(){ 
  Controller.Screen.clearLine();

  low.stop();
  storage.stop();
  high.stop();        
}

void storageOutRELEASED(){
  Controller.Screen.clearLine();

  storage.stop();
}
void middleGoalRELEASED(){
  Controller.Screen.clearLine();

  low.stop();
  high.stop();

}
void longGoalRELEASED(){
  Controller.Screen.clearLine();

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



void descore(){
  if (stateDescore==true){
    descoreOut();
    stateDescore=false; // Happy :)
  }else {
    descoreIn();
    stateDescore=true;
  }
}

void descoreTest(){
  Descore.set(true);
  wait(1,sec);
    Descore.set(false);

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
Controller.ButtonB.pressed(descore);
Controller.ButtonX.pressed(descoreIn);
Controller.ButtonY.pressed(descoreTest);

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
  Brain.Screen.print("in main v20251128-01");
  Controller.Screen.print("in main v20251128-01");
  wait(5,seconds);
  pre_auton();
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  //Competition.test_auton();
  //Competition.test_driver();
  while (true) {
    wait(100, msec);
  }
}
