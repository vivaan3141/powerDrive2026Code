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

using namespace vex;

// A global instance of competition
competition Competition;

void autonCodes(int x) {
  if (x==1){
      //drivePID(48,0.25,0.05,-0.1);
      Drivetrain.turnToHeading(90,degrees);

    // Auton Port 1
    //Scores 1 block on Middle goal and faces optimal position
    // Setup
    // Drivetrain.setDriveVelocity(40, percent);
    // low.setVelocity(200, rpm);
    // high.setVelocity(200, rpm);
    // storage.setVelocity(200, rpm);

    // drivePID(4,0.3,0.05,0.1);
    // turnPID(-90, 0.48,0,0);
    // low.spin(reverse);
    // //Make turns 
    // drivePID(32,0.3,0.05,0.1);
    // turnPID(-40, 0.5,0.05,0.1);
    
    // wait(1, sec);

    // drivePID(13,0.3,0.05,0.1);

    // wait(0.5, sec);

    // high.spin(reverse);
    // storage.spin(reverse);
    // low.spin(forward);
    // wait(2, sec);
    // high.stop();
    // storage.stop();
    // low.stop();
    // // drivePID(-15,0.3,0.05,0.1);
    // // turnPID(45, 0.5,0.05,0.1);
    

  } else if (x==2){
    drivePID(48,0.5,0,0);
    // Auton Port 2
    //Scores 1 block on Low goal and faces optimal position
    // Setup: 
    // Drivetrain.setDriveVelocity(20, percent);
    // low.setVelocity(200, rpm);
    // high.setVelocity(200, rpm);
    // storage.setVelocity(200, rpm);


    // drivePID(4,0.3,0.05,0.1);
    // turnPID(90, 0.48,0,0);
    // low.spin(reverse);
    // //Make turns 
    // drivePID(32,0.3,0.05,0.1);
    // turnPID(38, 0.5,0.05,0.1);
    
    // wait(1, sec);

    // drivePID(14.2,0.3,0.05,0.1);

    // wait(0.5, sec);

    // high.spin(reverse);
    // storage.spin(reverse);
    // low.spin(reverse);
    // wait(2, sec);
    // high.stop();
    // storage.stop();
    // low.stop();
    // // drivePID(-15,0.3,0.05,0.1);
    // // turnPID(45, 0.5,0.05,0.1);
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


    // Auton Port 4
    //Scores 4 block on Middle goal and faces optimal position
    // Setup
    Drivetrain.setDriveVelocity(40, percent);
    low.setVelocity(200, rpm);
    high.setVelocity(200, rpm);
    storage.setVelocity(200, rpm);

    drivePID(5,0.3,0.05,0.1);
    turnPID(-90, 0.48,0,0);
    

    //Make turns 
    drivePID(7,0.3,0.05,0.1);
    turnPID(-45, 0.5,0.05,0.1);
    
    wait(1, sec);

    drivePID(30,0.3,0.05,0.1);
    turnPID(128, 0.5,0.05,0.1);
    low.spin(forward);
    storage.spin(forward);
    drivePID(24,0.3,0.05,0.1);
    turnPID(-45, 0.5,0.05,0.1);
    drivePID(14,0.3,0.05,0.1);

    wait(0.5, sec);

    high.spin(reverse);
    storage.spin(reverse);
    low.spin(forward);
    wait(2, sec);
    high.stop();
    storage.stop();
    low.stop();
    
    // // Auton Port 4
    // //Scores 4 block on Middle goal and faces optimal position
    // // Setup
    // Drivetrain.setDriveVelocity(40, percent);
    // low.setVelocity(200, rpm);
    // high.setVelocity(200, rpm);
    // storage.setVelocity(200, rpm);

    // drivePID(3,0.3,0.05,0.1);
    // turnPID(-90, 0.48,0,0);
    // low.spin(forward);
    // storage.spin(forward);

    // //Make turns 
    // drivePID(32,0.3,0.05,0.1);
    // turnPID(-45, 0.5,0.05,0.1);
    
    // wait(1, sec);

    // drivePID(14.5,0.3,0.05,0.1);
    // drivePID(-1,0.3,0.05,0.1);
    // drivePID(1,0.3,0.05,0.1);


    // wait(0.5, sec);

    // high.spin(reverse);
    // storage.spin(reverse);
    // low.spin(forward);
    // wait(2, sec);
    // high.stop();
    // storage.stop();
    // low.stop();
    // // drivePID(-15,0.3,0.05,0.1);
    // // turnPID(45, 0.5,0.05,0.1);
  }else if(x==5){
    // Solo AWP All.2
    Drivetrain.setDriveVelocity(20, percent);
    low.setVelocity(200, rpm);
    high.setVelocity(200, rpm);
    storage.setVelocity(200, rpm);
    drivePID(4,0.1,0.00,0.0);
    Drivetrain.setDriveVelocity(100, percent);

  }else if (x==6){
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
  autonCodes(1);
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
  low.spin(forward);

  Controller.Screen.print("LONG GOAL");
}

// All released button functions


void reverseIntakeRELEASED(){
  low.stop();
}


    

    /*
    A more measured approach is to start with a low gain, 6:58 with integral and derivative disabled. 
    7:02 Watch the process and begin incrementally adjusting the gain 7:06 by doubling the value. 
    7:08 When the process begins to oscillate, 7:11 adjust the gain value down by 50%. 
    7:14 Employ a small integral value and watch the process. 
    7:19 Double the value incrementally 
    7:21 until oscillation occurs 
    7:23 then cut the integral by 50%. 
    7:26 At this point, you should be somewhere in the neighborhood 

    */ 


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
  low.stop();
}

void pida(){
  drivePID(24,0,0,0);
}

void pidb(){
  drivePID(48,0,0,0);
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
    
    //Tune Pid
    Controller.ButtonB.pressed(pida);
    Controller.ButtonY.pressed(pidb);



    

  while (true) {
    // ========== DRIVE CONTROL ========== //
    Drivetrain.setStopping(coast);

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
