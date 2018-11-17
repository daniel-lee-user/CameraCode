/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "shoot.h"
#include "../Robot.h"
#include <iostream>

shoot::shoot(double shootSpeed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::s_subsystem);
	shootSpeedInput = shootSpeed;
}

// Called just before this Command runs the first time
void shoot::Initialize() {
	SetTimeout(5); //set five second timeout
}

// Called repeatedly when this Command is scheduled to run
void shoot::Execute() {
	Robot::s_subsystem->shooterSpeed(shootSpeedInput);
	std::cout << Robot::s_subsystem->getSpeed() << std::endl;
}

// Make this return true when this Command no longer needs to run execute()
bool shoot::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void shoot::End() {
    Robot::s_subsystem->shooterSpeed(0);  // stop moving
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void shoot::Interrupted() {

}
