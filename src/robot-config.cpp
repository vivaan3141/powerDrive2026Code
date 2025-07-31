// src/robot-config.cpp
#include "robot-config.h"

//Configuration!

/*Reminders: 
Make sure that all your ports are different and correct! 
Make sure all of your motor + piston names are different and not confusing.
If it seems like some of your motors are running against eachother in the drivetrain, try switching around the true/false

*/

vex::brain Brain;
vex::controller Controller(vex::controllerType::primary);

vex::motor LB(vex::PORT5, vex::gearSetting::ratio6_1, true); //Left Back Motor
vex::motor LM(vex::PORT10, vex::gearSetting::ratio6_1, true); //Left Middle Motor
vex::motor LF(vex::PORT21, vex::gearSetting::ratio6_1, true); //Left Front Motor
vex::motor RB(vex::PORT4, vex::gearSetting::ratio6_1, false); //Right Back Motor
vex::motor RM(vex::PORT3, vex::gearSetting::ratio6_1, false); //Right Middle Motor
vex::motor RF(vex::PORT2, vex::gearSetting::ratio6_1, false); //Right Front Motor

vex::motor_group LeftDrive(LF, LM, LB);
vex::motor_group RightDrive(RF, RM, RB);

// Drivetrain: wheel travel = 320mm, track width = 280mm, wheelbase = 300mm (adjust as needed)
vex::drivetrain Drivetrain(LeftDrive, RightDrive);

vex::motor low (vex::PORT8,vex::gearSetting::ratio18_1); //Intake low
vex::motor high (vex::PORT7,vex::gearSetting::ratio18_1, true); //Intake high
//vex::motor storage (vex::?,vex::gearSetting::ratio18_1); //Bag storage


// vex::digital_out DoubleActingPiston (Brain.ThreeWirePort.A);
// vex::digital_out SingleActingPiston (Brain.ThreeWirePort.B);

vex::inertial InertialSensor(vex::PORT9);

void vexcodeInit() {
  InertialSensor.calibrate();
  // DoubleActingPiston.set(false); // retracted
  // SingleActingPiston.set(false); // off
  while (InertialSensor.isCalibrating()) {
    vex::task::sleep(100);
  }
}