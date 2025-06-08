#include "autons.h"
#include "robot-config.h"
#include "vex.h"
#include "functions.h"

using namespace vex;


void drivePID(double targetInches, double kP = 0.1, double kI = 0.1, double kD = 0.1) {

  double targetDegrees = inchesToDegrees(targetInches);

  setDTPosition(0); //reset encoders

  double error = targetDegrees;
  double integral = 0;
  double derivative = 0;
  double lastError = 0;
  double maxIntegral = 100;

  while (fabs(error) > 1.0) {
    double leftAvg = (LF.position(degrees) + LM.position(degrees) + LB.position(degrees)) / 3.0;
    double rightAvg = (RF.position(degrees) + RM.position(degrees) + RB.position(degrees)) / 3.0;
    double avgPos = (leftAvg + rightAvg) / 2.0;

    error = targetDegrees - avgPos;
    integral += error;

    // Anti-windup
    if (integral > maxIntegral) integral = maxIntegral;
    if (integral < -maxIntegral) integral = -maxIntegral;

    derivative = error - lastError;
    lastError = error;

    double power = (kP * error) + (kI * integral) + (kD * derivative);

    // Clamp output
    if (power > 100) power = 100;
    if (power < -100) power = -100;

    spinDT(power);

    task::sleep(20); // small loop delay
  }

  stopDT();

}

//WARNING:kP, kI, and kD values are not correct, need to update yourself
void turnPID(double targetAngle, double kP = 0.1, double kI = 0.1, double kD = 0.1) {

  // Reset inertial and motor encoders
  InertialSensor.setRotation(0, degrees);

  setDTPosition(0);

  double error = targetAngle;
  double integral = 0;
  double derivative = 0;
  double lastError = 0;
  double maxIntegral = 50;

  while (fabs(error) > 1.0) {
    double currentAngle = InertialSensor.rotation(degrees);
    error = targetAngle - currentAngle;

    integral += error;
    if (integral > maxIntegral) integral = maxIntegral;
    if (integral < -maxIntegral) integral = -maxIntegral;

    derivative = error - lastError;
    lastError = error;

    double turnPower = (kP * error) + (kI * integral) + (kD * derivative);

    // Clamp power
    if (turnPower > 100) turnPower = 100;
    if (turnPower < -100) turnPower = -100;

    // Left side spins backward, right side spins forward for clockwise turn
    spinRightDT(turnPower * -1);
    spinLeftDT(turnPower);

    vex::task::sleep(20);
  }

  // Stop all motors
  stopDT();

}