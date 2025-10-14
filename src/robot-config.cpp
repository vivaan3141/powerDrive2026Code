// src/robot-config.cpp
#include "robot-config.h"
using namespace vex;

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

vex::inertial InertialSensor(vex::PORT15);

vex::smartdrive Drivetrain = smartdrive(LeftDrive, RightDrive, InertialSensor, 279.5, 311.5, 254, mm, 0.6);

vex::motor low (vex::PORT8,vex::gearSetting::ratio18_1); //Intake low
vex::motor high (vex::PORT7,vex::gearSetting::ratio18_1, true); //Intake high
vex::motor storage (vex::PORT11,vex::gearSetting::ratio18_1); //Bag storage


// vex::digital_out DoubleActingPiston (Brain.ThreeWirePort.A);
// vex::digital_out SingleActingPiston (Brain.ThreeWirePort.B);


void vexcodeInit() {
  InertialSensor.calibrate();
  // DoubleActingPiston.set(false); // retracted
  // SingleActingPiston.set(false); // off
  while (InertialSensor.isCalibrating()) {
    vex::task::sleep(100);
  }
}