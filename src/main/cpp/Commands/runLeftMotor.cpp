/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "runLeftMotor.h"
#include "../Robot.h"
#include "../Utilities/NetworkTables.h"


runLeftMotor::runLeftMotor(double leSpeed) {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::t_subsystem);
	tempSpeed = leSpeed;

}

// Called just before this Command runs the first time
void runLeftMotor::Initialize() {
	SetTimeout(5); //set five second timeout
}

// Called repeatedly when this Command is scheduled to run
void runLeftMotor::Execute() {
	Robot::t_subsystem->setLeftSpeed(tempSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool runLeftMotor::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void runLeftMotor::End() {
    Robot::t_subsystem->setLeftSpeed(0);  // stop moving
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void runLeftMotor::Interrupted() {

}
