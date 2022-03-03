/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Carter Wobbe                                                       */
/*    Created:      Thu 11/11/21                                           */
/*    Description:                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// MotorLeft            motor         8               
// MotorRight           motor         2               
// Lifter               motor_group   3, 7            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// static DrivetrainRotate(deg){
//   int i = deg;

// };




// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  MotorLeft.setStopping(coast);
  MotorRight.setStopping(coast);
  Lifter.setStopping(hold);//should be hold
  
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
    int distancee = 7.5;
    float degrees = 10.97;
  //Drivetrain.driveFor(forward, 2, inches);
      MotorRight.setVelocity(75, percent);
      MotorLeft.setVelocity(75, percent);

      MotorRight.spinFor(forward, distancee, turns, false);
      MotorLeft.spinFor(forward, distancee, turns);
      MotorLeft.spinFor(forward, degrees/2, turns);
      MotorRight.spinFor(forward, distancee/1.5, turns, false);
      MotorLeft.spinFor(forward, distancee/1.5, turns);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while(1) {
    int RStickX = Controller1.Axis1.position(); //variables for stick position
    int RStickY = Controller1.Axis2.position();
    int LStickX = Controller1.Axis4.position();
    int LStickY = Controller1.Axis3.position();

    int LeftSpeed = LStickY; //variable that will control moter velocity
    int RightSpeed = RStickY;

    if (LeftSpeed > 100){LeftSpeed = 100;} //makes variable a number between (-100, 100)
    if (LeftSpeed < -100){LeftSpeed = -100;}
    if (RightSpeed > 100){RightSpeed = 100;}
    if (RightSpeed < -100){RightSpeed = -100;}

    if (Controller1.ButtonB.pressing()){ //turn 360 degrees (for testing)
      MotorLeft.setVelocity(0, percent);
      MotorRight.setVelocity(100, percent);
      MotorRight.spinFor(forward, 10.97, turns);

    }
    else if(Controller1.ButtonA.pressing()) //Run autonomous
    {
      autonomous();
    }
    else{
      MotorLeft.setVelocity(LeftSpeed, percent);
      MotorRight.setVelocity(RightSpeed, percent);

      MotorLeft.spin(forward);
      MotorRight.spin(forward);
    }


  if (Controller1.ButtonUp.pressing()){
    Lifter.setVelocity(50, percent);
    Lifter.spin(forward);

  } else if (Controller1.ButtonDown.pressing()){
    Lifter.setVelocity(50, percent);
    Lifter.spin(reverse);

  } else {
    Lifter.setVelocity(0, percent);
    Lifter.stop();

  }
      wait(20, msec);
      }
  }
//
//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
