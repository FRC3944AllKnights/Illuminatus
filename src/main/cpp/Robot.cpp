/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <thread> 

#include <frc/TimedRobot.h>
#include <frc/Joystick.h>
#include <frc/drive/DifferentialDrive.h>

#include "Drive.h"
#include "WheelSpinnies.h"

/** This is a test
 * This is a demo program showing how to use Mecanum control with the
 * MecanumDrive class.
 */
class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override {
    // Invert the left side motors. You may need to change or remove this to
    // match your robot.
    LOCDrive.init();
    Shoot.init();
  }

  void TeleopPeriodic() override {
    /* Use the joystick X axis for lateral movement, Y axis for forward
     * movement, and Z axis for rotation.
     */
    LOCDrive.Arcade(-m_stick.GetRawAxis(1), -m_stick.GetRawAxis(4));
    Shoot.spinrev(m_stick.GetRawButton(1), m_stick.GetRawButton(2));
  }

 private:
 //this is where to change variables
  static constexpr int kJoystickChannel = 0;
  Drive LOCDrive;
  WheelSpinnies Shoot;
  frc::Joystick m_stick{kJoystickChannel};
};

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif