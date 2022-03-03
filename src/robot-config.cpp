#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor MotorLeft = motor(PORT8, ratio18_1, true);
motor MotorRight = motor(PORT2, ratio18_1, false);
motor LifterMotorA = motor(PORT3, ratio36_1, false);
motor LifterMotorB = motor(PORT7, ratio36_1, true);
motor_group Lifter = motor_group(LifterMotorA, LifterMotorB);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}