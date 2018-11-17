/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "runRightMotor.h"
#include "../Robot.h"

runRightMotor::runRightMotor(double riSpeed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::t_subsystem);
	tempSpeed = riSpeed;

}

// Called just before this Command runs the first time
void runRightMotor::Initialize() {
	SetTimeout(5); //set five second timeout
}

// Called repeatedly when this Command is scheduled to run
void runRightMotor::Execute() {
	Robot::t_subsystem->setRightSpeed(tempSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool runRightMotor::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void runRightMotor::End() {
    Robot::t_subsystem->setRightSpeed(0);  // stop moving
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void runRightMotor::Interrupted() {

}
