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
#include "arm.h"
#include "functions.h"

using namespace vex;

// A global instance of competition
competition Competition;


void pre_auton(void) {

  vexcodeInit();
  displayAutonSelector();
  
}

void autonomous(void) {
  
  // switch (getSelectedAuton()) {
  //   case 0:
  //     rightAuton();
  //     break;
  //   case 1:
  //     leftAuton();
  //     break;
  //   case 2:
  //     skillsAuton();
  //     break;
  //   default:
  //     Brain.Screen.print("No valid auton selected!");
  //     break;
  // }
 


}


void usercontrol(void) {

  while (true) {
    // ========== DRIVE CONTROL ========== //

    double fwd = Controller.Axis3.position();
    double turn = Controller.Axis1.position();

    double leftPower  = fwd + turn;
    double rightPower = fwd - turn;

    spinLeftDT(leftPower * 0.7);
    spinRightDT(rightPower * 0.7);

    
      

    // ========== Conveyor Control ========== //
    if (Controller.ButtonA.pressing()) { // Left side front buttons
      low.setVelocity(200, rpm);
      high.setVelocity(200, rpm);
      Controller.Screen.print("REVERSE ALL");
      low.spin(reverse);
      high.spin(reverse); // descore all stages
      
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
      high.spin(reverse); // Scores middle goal, moves low stage and medium stage in normal, and high stage in reverse for extra push
      Controller.Screen.print("Middle Goal");

    } else if (Controller.ButtonR2.pressing()) {
      low.setVelocity(200, rpm);
      high.setVelocity(200, rpm);

      low.spin(forward);
      high.spin(forward); // Score long, moves all stages
      Controller.Screen.print("LONG GOAL");

       // intake  open
    }else{
      low.stop();
      high.stop(); 
      Controller.Screen.print("POWER-DRIVE:13707X!");

    }

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
