/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "moveForward.h"
#include "../Robot.h"
#include "../Utilities/NetworkTables.h"

moveForward::moveForward() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::t_subsystem);
}

// Called just before this Command runs the first time
void moveForward::Initialize() {
	SetTimeout(5); //set five second timeout
}

// Called repeatedly when this Command is scheduled to run
void moveForward::Execute() {
	Robot::t_subsystem->tankDrive(0.2, 0.2);
}

// Make this return true when this Command no longer needs to run execute()
bool moveForward::IsFinished() {
	if(NetworkTables::getDistanceCV() >= 10) {
		return true;
	}
	else {
		return false;
	}

}

// Called once after isFinished returns true
void moveForward::End() {
    Robot::t_subsystem->tankDrive(0,0);  // stop moving
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void moveForward::Interrupted() {

}
