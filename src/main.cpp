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

    // if (Controller.ButtonA.pressing()) {
      
    // } else if (Controller.ButtonB.pressing()) {
    // } else {
      

    // ========== CLAMP CONTROL ========== //
    if (Controller.ButtonL1.pressing()) {
      low.setVelocity(200, rpm);
      middle.setVelocity(200, rpm);
      high.setVelocity(200, rpm);

      low.spin(reverse);
      middle.spin(reverse);
      high.spin(reverse); // descore all stages
      

    }


    if (Controller.ButtonR1.pressing()) {
      low.setVelocity(200, rpm);
      middle.setVelocity(200, rpm);
      high.setVelocity(200, rpm);

      low.spin(forward);
      middle.spin(forward);
      high.spin(reverse); // Scores middle goal, moves low stage and medium stage in normal, and high stage in reverse for extra push
      
    } else if (Controller.ButtonR2.pressing()) {
      low.setVelocity(200, rpm);
      middle.setVelocity(200, rpm);
      high.setVelocity(200, rpm);
      
      low.spin(forward);
      middle.spin(forward);
      high.spin(forward); // Score long, moves all stages



       // intake  open
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
