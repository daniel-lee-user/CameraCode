/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include "WPILib.h"
#include <WPILib.h>
#include "Robot.h"
#include "Commands/moveForwardShoot.h"
#include "Commands/runLeftRightMotors.h"
#include "Commands/ExampleCommand.h"
#include "Commands/TankDrive.h"
#include "Commands/PIDShoot.h"

OI::OI(): rightMotorStick(new Joystick(1)),
          leftMotorStick(new Joystick(0)),
		  shooterButton(new JoystickButton(leftMotorStick, 1)),
		  runLeftRight(new JoystickButton(rightMotorStick, 1)),
		  PIDShootButton(new JoystickButton(rightMotorStick, 2)){
	// Process operator interface input here.
	//shooterButton ->WhenPressed(new moveForwardShoot(0.2));
	runLeftRight ->WhenPressed(new runLeftRightMotors(0.2, -0.2));
	PIDShootButton->WhenPressed(new PIDShoot());
}

Joystick* OI::getRightMotorStick() {
	return rightMotorStick;
}

Joystick* OI::getLeftMotorStick() {
	return leftMotorStick;
}
