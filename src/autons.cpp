#include "robot-config.h"
#include "vex.h"
#include "PID.h"
#include "functions.h"


using namespace vex;


void auton(int x) {
  if (x==1){
    Drivetrain.setDriveVelocity(60, percent);
    low.setVelocity(200, rpm);
    high.setVelocity(200, rpm);
    storage.setVelocity(200, rpm);

    drivePID(3,0.3,0.05,0.1);
    turnPID(-90, 0.48,0,0);
    storage.spin(forward);
    low.spin(reverse);
    //Make turns 
    drivePID(36,0.3,0.05,0.1);
    turnPID(-45, 0.5,0.05,0.1);
    
    wait(0.5, sec);

    drivePID(15,0.3,0.05,0.1);

    wait(0.5, sec);

    high.spin(reverse);
    storage.spin(reverse);
    low.spin(reverse);
    wait(2, sec);
    high.stop();
    storage.stop();
    low.stop();
    drivePID(-15,0.3,0.05,0.1);
    turnPID(-90, 0.5,0.05,0.1);
    drivePID(60,0.3,0.05,0.1);
    turnPID(45, 0.5,0.05,0.1);
    drivePID(15,0.3,0.05,0.1);

    high.spin(reverse);
    storage.spin(reverse);
    low.spin(reverse);

  } else if (x==2){
    Drivetrain.setDriveVelocity(60, percent);
    low.setVelocity(200, rpm);
    high.setVelocity(200, rpm);
    storage.setVelocity(200, rpm);

    drivePID(3,0.3,0.05,0.1);
    turnPID(90, 0.48,0,0);
    storage.spin(forward);
    low.spin(reverse);
    //Make turns 
    drivePID(36,0.3,0.05,0.1);
    turnPID(45, 0.5,0.05,0.1);
    
    wait(0.5, sec);

    drivePID(15,0.3,0.05,0.1);

    wait(0.5, sec);


    high.spin(reverse);
    storage.spin(reverse);
    low.spin(reverse);
    wait(2, sec);
    high.stop();
    storage.stop();
    low.stop();

    drivePID(-15,0.3,0.05,0.1);
    turnPID(90, 0.5,0.05,0.1);
    drivePID(60,0.3,0.05,0.1);
    turnPID(-45, 0.5,0.05,0.1);
    drivePID(15,0.3,0.05,0.1);

    high.spin(reverse);
    storage.spin(reverse);
    low.spin(reverse);
  } else if (x==3){
    Drivetrain.setDriveVelocity(60, percent);
    low.setVelocity(200, rpm);
    high.setVelocity(200, rpm);
    storage.setVelocity(200, rpm);

    drivePID(3,0.3,0.05,0.1);
    turnPID(-90, 0.48,0,0);
    storage.spin(forward);
    low.spin(reverse);
    //Make turns 
    drivePID(36,0.3,0.05,0.1);
    turnPID(-45, 0.5,0.05,0.1);
    
    wait(0.5, sec);

    drivePID(15,0.3,0.05,0.1);

    wait(0.5, sec);

    high.spin(reverse);
    storage.spin(reverse);
    low.spin(reverse);
    wait(2, sec);
    high.stop();
    storage.stop();
    low.stop();
    drivePID(-40,0.3,0.05,0.1);
    turnPID(45, 0.5,0.05,0.1);
    drivePID(20,0.3,0.05,0.1);
    //Score Long goal

  }else if (x==4){
    //DO long goal for other side
  }else{
    //Skills Auton
    Drivetrain.setDriveVelocity(60, percent);
    low.setVelocity(200, rpm);
    high.setVelocity(200, rpm);
    storage.setVelocity(200, rpm);

    drivePID(3,0.3,0.05,0.1);
    turnPID(-90, 0.48,0,0);
    storage.spin(forward);
    low.spin(reverse);
    //Make turns 
    drivePID(36,0.3,0.05,0.1);
    turnPID(-45, 0.5,0.05,0.1);
    
    wait(0.5, sec);

    drivePID(15,0.3,0.05,0.1);

    wait(0.5, sec);

    high.spin(reverse);
    storage.spin(reverse);
    low.spin(reverse);
    wait(2, sec);
    high.stop();
    storage.stop();
    low.stop();
    drivePID(-15,0.3,0.05,0.1);
    turnPID(-90, 0.5,0.05,0.1);
    drivePID(60,0.3,0.05,0.1);
    turnPID(45, 0.5,0.05,0.1);
    drivePID(15,0.3,0.05,0.1);

    high.spin(reverse);
    storage.spin(reverse);
    low.spin(reverse);

    high.spin(reverse);
    storage.spin(reverse);
    low.spin(reverse);
    wait(2, sec);
    high.stop();
    storage.stop();
    low.stop();
    drivePID(-40,0.3,0.05,0.1);
    turnPID(45, 0.5,0.05,0.1);
    drivePID(20,0.3,0.05,0.1);
    //Score Long goal

  }
}

