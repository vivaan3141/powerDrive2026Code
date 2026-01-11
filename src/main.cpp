/*    Module:       main.cpp                               */
/*    Author:       Vivaan Gupta                           */
/*    Created:      5/27/2025, 10:30:19 PM                 */
// January 10. Autonomous change for Jan 10
#include "vex.h"
#include "robot-config.h"
#include "PID.h"
#include "functions.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace vex;
competition Competition;


bool stateLoader=false;
bool stateDescore=false;

double distance(){
  return gap.objectDistance(inches);
}

void driveUntilTarget(double distance, double speed) {
  double targetDistRaw=(gap.objectDistance(inches))-(distance); // this gives the og target 
  double targetDist = std::round(targetDistRaw * 10.0) / 10.0; // this supposed to round so there no oscillation
  double driveSpeed=speed; // for reducing speed??
  Drivetrain.setDriveVelocity(speed, percent);

  while (targetDist!=distance){ // this logic supposed to make it go to accurate number
    // driveSpeed=driveSpeed-1;
    // Drivetrain.setDriveVelocity(driveSpeed, percent); 
    // THIS LOGIC-  supposed to reduce speed when its close, not done, so im not doing it yet

    if (targetDist>distance){
      Drivetrain.drive(forward);
      targetDist=gap.objectDistance(inches)-(distance);
  }else if(targetDist<distance){
      Drivetrain.drive(reverse);
      targetDist=gap.objectDistance(inches)-(distance);
    }
  }
  Drivetrain.stop();
}

void driveToDist(double distance, double speed){
double targetDistRaw=gap.objectDistance(inches); // this gives the og target 
  double targetDist = std::round(targetDistRaw * 10.0) / 10.0; // this supposed to round so there no oscillation
  double driveSpeed=speed; // for reducing speed??
  double distR=std::round(distance * 10.0) / 10.0;
  Drivetrain.setDriveVelocity(speed, percent);
  
  while (targetDist!=distR){ // this logic supposed to make it go to accurate number
    // driveSpeed=driveSpeed-1;
    // Drivetrain.setDriveVelocity(driveSpeed, percent); 
    // THIS LOGIC-  supposed to reduce speed when its close, not done, so im not doing it yet
    if (targetDist>distR){
      Drivetrain.drive(forward);
      targetDist=gap.objectDistance(inches)-(distance);
  }else if(targetDist<distR){
      Drivetrain.drive(reverse);
      targetDist=gap.objectDistance(inches)-(distance);
    }
  }
  Drivetrain.stop();
  }

void turn(int deg, std::string dir){
  if (dir == "left" or "l"){
    Drivetrain.turnToHeading(deg,degrees);
  }else if (dir == "right" or "r"){
    Drivetrain.turnToHeading((0-deg),degrees);
  }
}

void setSpeedAuton(){
    Loader.set(false);
    Descore.set(false);
    low.setVelocity(150, rpm);
    high.setVelocity(200, rpm);
    storage.setVelocity(200, rpm);
}

void loadLoop(int loop, double dist, double time){
  for (int i=0; i<loop; i++){
    Drivetrain.driveFor(dist,inches);
    wait(time, sec);
    Drivetrain.driveFor((0-dist),inches);
  }
}


void autonCodes(int x) {
  if (x==1){
    // Auton code 1#, Long Goal 3 Blocks. Side: 
  Controller.Screen.print("V67");
   /// Long Goal 1
   Loader.set(false);
   Drivetrain.setDriveVelocity(15, percent);
   low.setVelocity(150, rpm);
   high.setVelocity(200, rpm);
   storage.setVelocity(200, rpm);
//A
   Drivetrain.driveFor(32.5,inches);
       Loader.set(true);
   Drivetrain.turnToHeading(90, degrees);
   // wait(0.75, sec);
   storage.spin(forward);
   Drivetrain.setDriveVelocity(10, percent);
   Drivetrain.setTurnVelocity(8, percent);
   Drivetrain.setTurnConstant(0.6);


   Drivetrain.driveFor(10,inches);
//Takes out
   low.spin(forward);
   Drivetrain.driveFor(2.5,inches);


   Drivetrain.driveFor(-1.5,inches);
   wait(0.1, sec);
  
   Drivetrain.driveFor(1.5,inches);
   wait(0.1, sec);
   Drivetrain.driveFor(-1.5,inches);


   Drivetrain.driveFor(0.5,inches);
   wait(0.1, sec);
   Drivetrain.driveFor(-0.5,inches);


   wait(0.1, sec);
   Drivetrain.driveFor(-6,inches);
   Loader.set(false);
   Drivetrain.setDriveVelocity(20, percent);

   // GO to long Goal  
   Drivetrain.driveFor(-18,inches);
   storage.stop();
   low.stop();
   Drivetrain.setDriveVelocity(10, percent);


   Drivetrain.driveFor(-3,inches);


 //Scores in goal 1 Note: Will need to change based on motors
   high.spin(forward);
   storage.spin(reverse);
   low.spin(forward);

}
}

// Pre-Autonomous
void pre_auton(void) {
  Loader.set(false);
  vexcodeInit();
  InertialSensor.calibrate();  // Start calibration. Print that the Inertial Sensor is calibrating
  low.setVelocity(200, rpm); high.setVelocity(200, rpm);
  while(InertialSensor.isCalibrating()){
    Brain.Screen.print("Inertial Calibrating"); wait(5, sec);
  }
}
// USER CONTROLS

void autonomous() {
  Drivetrain.setStopping(hold);
  autonCodes(8);
}
 
void reverseIntake(){
  low.spin(reverse);
  high.spin(reverse);
}

void middleGoal(){
  low.spin(forward);
  high.spin(reverse);
  Controller.Screen.print("Middle Goal");
}

void intake(){
  low.spin(forward);
  Controller.Screen.print("Intake");
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

void intakeRELEASED(){
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




void PID(){
  drivePID(24,0.1,0.05,-0.1);
}

void usercontrol(void) {
  high.setVelocity(200, rpm);
  low.setVelocity(200, rpm);
  storage.setVelocity(200, rpm);

  Controller.ButtonA.pressed(reverseIntake);
  Controller.ButtonA.released(reverseIntakeRELEASED);

  Controller.ButtonR1.pressed(middleGoal);
  Controller.ButtonR1.released(middleGoalRELEASED);

  Controller.ButtonR2.pressed(longGoal);
  Controller.ButtonR2.released(longGoalRELEASED);

  Controller.ButtonL1.pressed(intake);
  Controller.ButtonL1.released(intakeRELEASED);




  // Pneumatics
  Controller.ButtonUp.pressed(load);
  Controller.ButtonB.pressed(descore);
  Controller.ButtonX.pressed(PID);

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
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  while (true) {
    wait(100, msec);
  }
}
