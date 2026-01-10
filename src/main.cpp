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
int x=0;

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




// enum Direction {
//   left,
//   right
// };

// void turn(int deg, Direction dir){
//   if (dir == left){
//     Drivetrain.turnToHeading(deg,degrees);
//   }else if (dir == right){
//     Drivetrain.turnToHeading((0-deg),degrees);
//   }
// }

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


void autonCodes(int x) {
  if (x==1){
    Loader.set(false);
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
    Loader.set(false);
    Drivetrain.setDriveVelocity(10, percent);
    low.setVelocity(200, rpm);
    high.setVelocity(200, rpm);
    storage.setVelocity(200, rpm);
//A
    //drivePID(26.5,0.1,0.05,0.1);
    Drivetrain.driveFor(33,inches);
    Drivetrain.turnToHeading(-90, degrees);
    Loader.set(true);
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
    Loader.set(false);
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
    Drivetrain.turnToHeading(-90, degrees);
    // wait(0.75, sec);
    storage.spin(forward);
    Drivetrain.setDriveVelocity(15, percent);
    Drivetrain.setTurnVelocity(8, percent);
    Drivetrain.setTurnConstant(0.6);
    Drivetrain.setDriveVelocity(10, percent);


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
    Drivetrain.setDriveVelocity(15, percent);

    wait(0.1, sec);
    Drivetrain.driveFor(-6,inches);
    Loader.set(false);
    Drivetrain.setDriveVelocity(20, percent);

    // GO to long Goal  1
    Drivetrain.turnToHeading(87, degrees);
    // Drivetrain.turnToHeading(90, degrees);
    double value = InertialSensor.heading();
    std::cout<<"Degrees: "<<value;
        Controller.Screen.print(value);

    Drivetrain.driveFor(18,inches);
    storage.stop();
    low.stop();
    Drivetrain.setDriveVelocity(10, percent);

    Drivetrain.driveFor(2.5,inches);

  //Scores in goal 1
    high.spin(forward);
    storage.spin(reverse);
    low.spin(forward);
    
    // wait(0.3, sec);

    // high.stop();
    // storage.spin(forward);
    // low.stop();
    //     wait(0.3, sec);

    // high.spin(forward);
    // storage.spin(reverse);
    // low.spin(forward);
    
  }else if(x==6){
    
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

    // GO to long Goal  1
    Drivetrain.turnToHeading(-86.5, degrees);
    // Drivetrain.turnToHeading(90, degrees);
    double value = InertialSensor.heading();
    std::cout<<"Degrees: "<<value;
        Controller.Screen.print(value);
    Drivetrain.setDriveVelocity(15, percent);

    Drivetrain.driveFor(18,inches);
    storage.stop();
    low.stop();
    Drivetrain.setDriveVelocity(10, percent);

    Drivetrain.driveFor(3,inches);

  //Scores in goal 1
    high.spin(forward);
    storage.spin(reverse);
    low.spin(forward);

  }else if (x==7){

Controller.Screen.print("V67");
    /// Long Goal 1
    Loader.set(false);
    Drivetrain.setDriveVelocity(10, percent);
    low.setVelocity(150, rpm);
    high.setVelocity(200, rpm);
    storage.setVelocity(200, rpm);
//A
    Drivetrain.driveFor(32.5,inches);
        Loader.set(true);
    Drivetrain.turnToHeading(-90, degrees);
    // wait(0.75, sec);
    storage.spin(forward);
    Drivetrain.setDriveVelocity(10, percent);
    Drivetrain.setTurnVelocity(8, percent);
    Drivetrain.setTurnConstant(0.6);


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

    Drivetrain.driveFor(-6,inches);
    Loader.set(false);
    Drivetrain.setDriveVelocity(20, percent);

    // GO to long Goal  1
    Drivetrain.turnToHeading(87, degrees);
    // Drivetrain.turnToHeading(90, degrees);
    double value = InertialSensor.heading();
    std::cout<<"Degrees: "<<value;
        Controller.Screen.print(value);

    Drivetrain.driveFor(18,inches);
    storage.stop();
    low.stop();
    Drivetrain.setDriveVelocity(10, percent);

    Drivetrain.driveFor(2.5,inches);

  //Scores in goal 1
    high.spin(forward);
    storage.spin(reverse);
    low.spin(forward);

    wait (3, seconds);

    high.stop();
    low.stop();
    storage.stop();
// Next Loader, turns back then long stretch
     // MAJOR EDITs - DEF START

    Drivetrain.driveFor(-9,inches);

        Drivetrain.turnToHeading(0, degrees);

     Drivetrain.driveFor(-40,inches);
        Drivetrain.turnToHeading(0, degrees);
     Drivetrain.driveFor(-40,inches);

        Drivetrain.turnToHeading(-90, degrees);


    wait (0.5, seconds);
     Drivetrain.driveFor(15,inches);
     // MAJOR EDITs - DEF END

    // Loader time

    low.spin(forward);
    Drivetrain.driveFor(2.5,inches);

    Drivetrain.driveFor(-1.5,inches);
    wait(0.1, sec);
    
    Drivetrain.driveFor(1.5,inches);
    wait(0.1, sec);
    Drivetrain.driveFor(-1.5,inches);

    Drivetrain.driveFor(2,inches);
    wait(0.1, sec);
    Drivetrain.driveFor(-2,inches);

    Drivetrain.driveFor(2,inches);
    wait(0.1, sec);
    Drivetrain.driveFor(-2,inches);

    Drivetrain.driveFor(2,inches);
    wait(0.1, sec);
    Drivetrain.driveFor(-2,inches);

    Drivetrain.driveFor(2,inches);
    wait(0.1, sec);
    Drivetrain.driveFor(-2,inches);

    Drivetrain.driveFor(1.5,inches);
    wait(0.1, sec);
    Drivetrain.driveFor(-1.5,inches);

    wait(0.1, sec);
    Drivetrain.driveFor(-6,inches);
    Loader.set(false);
    Drivetrain.setDriveVelocity(20, percent);

    // GO to long Goal  1
    Drivetrain.turnToHeading(87, degrees);
    // Drivetrain.turnToHeading(90, degrees);
    double val = InertialSensor.heading();
    std::cout<<"Degrees: "<<val;
        Controller.Screen.print(value);

    Drivetrain.driveFor(18,inches);
    storage.stop();
    low.stop();
    Drivetrain.setDriveVelocity(10, percent);

    Drivetrain.driveFor(2.5,inches);

  //Scores in goal 2
    high.spin(forward);
    storage.spin(reverse);
    low.spin(forward);

    wait (3, seconds);

    high.stop();
    low.stop();
    storage.stop();

    // Time for a park
    Drivetrain.driveFor(-9,inches);
    Drivetrain.turnToHeading(0, degrees);
    
    Drivetrain.driveFor(52,inches);
    Drivetrain.setDriveVelocity(20, percent);
    Drivetrain.turnToHeading(90, degrees);
    Drivetrain.driveFor(-22,inches);
    wait(1, sec);
    Drivetrain.driveFor(-10,inches);
  }else if (x==8){
    Loader.set(false);
    Drivetrain.setDriveVelocity(19, percent);
    low.setVelocity(140, rpm);
    high.setVelocity(200, rpm);
    storage.setVelocity(200, rpm);
//A
    //drivePID(26.5,0.1,0.05,0.1);
    Drivetrain.driveFor(33,inches);
    Drivetrain.turnToHeading(-90, degrees);
    Loader.set(true);
    wait(1, sec);
    storage.spin(forward);
    Drivetrain.setDriveVelocity(14, percent);
    Drivetrain.driveFor(9,inches);
//Takes out
    low.spin(forward);

    Drivetrain.driveFor(3,inches);
    Drivetrain.driveFor(-3,inches);
    wait(0.5, sec);
    Drivetrain.driveFor(3,inches);
    Drivetrain.driveFor(-3,inches);
    wait(0.5, sec);
    Drivetrain.driveFor(3,inches);
    Drivetrain.driveFor(-3,inches);
    wait(0.5, sec);
    Drivetrain.driveFor(3,inches);
    Drivetrain.driveFor(-3,inches);
    wait(0.5, sec);

    
     storage.stop();


   Drivetrain.driveFor(3,inches);
    Drivetrain.driveFor(-3,inches);
    wait(0.5, sec);
    Drivetrain.driveFor(3,inches);
    Drivetrain.driveFor(-3,inches);
    wait(0.5, sec);
    Drivetrain.driveFor(3,inches);
    Drivetrain.driveFor(-3,inches);
    wait(0.5, sec);
    Drivetrain.driveFor(3,inches);
    Drivetrain.driveFor(-3,inches);
    wait(0.5, sec);

//d
    Drivetrain.driveFor(-6,inches);
    Loader.set(false);
    storage.stop();

    // GO to long Goal  1
    Drivetrain.turnToHeading(0, degrees);
    high.spin(reverse);
    low.spin(forward);
      storage.spin(reverse);
    wait(1, sec);
   high.stop();
    storage.stop();
    low.stop();
    Drivetrain.turnToHeading(87, degrees);
    Drivetrain.driveFor(20,inches);

    
  //Scores in goal 1
    high.spin(forward);
    storage.spin(reverse);
    low.spin(forward);
    wait(5, sec);

    high.stop();
    storage.stop();
    low.stop();
        
    Drivetrain.driveFor(-9,inches);
    Drivetrain.turnToHeading(0, degrees);

        Drivetrain.setDriveVelocity(28, percent);
high.spin(reverse);
    storage.spin(reverse);
    low.spin(forward);
    
    
    Drivetrain.driveFor(-102,inches);
    high.stop();
    storage.stop();
    low.stop();

    Drivetrain.turnToHeading(0, degrees);

    wait(0.3, sec);
    Drivetrain.turnToHeading(-90, degrees);


Loader.set(true);
    storage.spin(forward);
    Drivetrain.setDriveVelocity(10, percent);
    Drivetrain.driveFor(15.75,inches);

//Takes out
    low.spin(forward);
            Drivetrain.turnToHeading(-90, degrees);
    Drivetrain.driveFor(2,inches);
    Drivetrain.driveFor(-2,inches);
    wait(0.5, sec);
     Drivetrain.driveFor(2,inches);
    Drivetrain.driveFor(-2,inches);
    wait(0.5, sec);
   Drivetrain.driveFor(2,inches);
    Drivetrain.driveFor(-2,inches);
    wait(0.5, sec);
   Drivetrain.driveFor(2,inches);
    Drivetrain.driveFor(-2,inches);
    wait(0.5, sec);


  Drivetrain.driveFor(2,inches);
    Drivetrain.driveFor(-2,inches);
    wait(0.5, sec);

         storage.stop();

   Drivetrain.driveFor(2,inches);
    Drivetrain.driveFor(-2,inches);
    wait(0.5, sec);
  Drivetrain.driveFor(2,inches);
    Drivetrain.driveFor(-2,inches);
    wait(0.5, sec);
 Drivetrain.driveFor(2,inches);
    Drivetrain.driveFor(-2,inches);
    wait(0.5, sec);
  Drivetrain.driveFor(2,inches);
    Drivetrain.driveFor(-2,inches);
    wait(0.5, sec);
 
    Drivetrain.setDriveVelocity(20, percent);

Drivetrain.driveFor(-4.5,inches);
    Loader.set(false);
    Drivetrain.turnToHeading(-90, degrees);
      low.stop();

Drivetrain.turnToHeading(180, degrees);
    high.spin(reverse);
    low.spin(forward);
      storage.spin(reverse);

    wait(1, sec);
  high.stop();
    storage.stop();
    low.stop();
    // GO to long Goal  1
    Drivetrain.turnToHeading(87, degrees);
  
        Drivetrain.setDriveVelocity(15, percent);

    Drivetrain.driveFor(20,inches);
       
    Drivetrain.driveFor(4,inches);
//.

    //.
  //Scores in goal 1
    high.spin(forward);
    storage.spin(reverse);
    low.spin(forward);
    Drivetrain.turnToHeading(90, degrees);
    wait(6, sec);
    high.stop();
    storage.stop();
    low.stop();


    Drivetrain.driveFor(-9,inches);
    Drivetrain.turnToHeading(0, degrees);

    Drivetrain.setDriveVelocity(35, percent);

    Drivetrain.driveFor(52,inches);
    Drivetrain.setDriveVelocity(20, percent);
    Drivetrain.turnToHeading(90, degrees);
    Drivetrain.driveFor(-22,inches);
    wait(1, sec);
    Drivetrain.driveFor(-10,inches);  
  }else if(x==9){
    Drivetrain.setDriveVelocity(10, percent);
    Drivetrain.driveFor(5,inches);
    Drivetrain.setDriveVelocity(20, percent);
    wait(1, sec);
    Drivetrain.driveFor(-22,inches);
    wait(1, sec);
    Drivetrain.driveFor(-10,inches); 
  }else if (x==10){
      Drivetrain.driveFor(6,inches);
  }
}

// Pre-Autonomous

void pre_auton(void) {
  Loader.set(false);

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
  autonCodes(8);
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
void tempStore(){
    Controller.Screen.print(storage.temperature(celsius)); 
}



void PID(){
  drivePID(24,0.1,0.05,-0.1);
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
  Controller.ButtonY.released(tempStore);

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
  //Competition.test_auton();
  //Competition.test_driver();
  while (true) {
    wait(100, msec);
  }
}
