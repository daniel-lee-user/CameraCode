/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "PIDShoot.h"
#include "../Utilities/WVPIDController.h"
#include "../Robot.h"
#include <iostream>

PIDShoot::PIDShoot(): PIDObject(new WVPIDController(0.05, 0.01, 0.01, 5.0, false)) {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::s_subsystem);
	power = 0;
}

// Called just before this Command runs the first time
void PIDShoot::Initialize() {
	PIDObject-> SetSetPoint(5.0);
}

// Called repeatedly when this Command is scheduled to run
void PIDShoot::Execute() {
	power = PIDObject->Tick(Robot::s_subsystem->getSpeed());
	Robot::s_subsystem->shooterSpeed(power);
}

// Make this return true when this Command no longer needs to run execute()
bool PIDShoot::IsFinished() {
	if(PIDObject->GetError() <= 0.1) {
		std::cout << "Shooter Continuous value: " << Robot::s_subsystem->getSpeed() << std::endl;
	}
	return false;
}

// Called once after isFinished returns true
void PIDShoot::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PIDShoot::Interrupted() {

}
