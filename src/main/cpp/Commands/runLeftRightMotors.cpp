/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "runLeftRightMotors.h"
#include "runRightMotor.h"
#include "runLeftMotor.h"
#include <iostream>


runLeftRightMotors::runLeftRightMotors(double iRSpeed, double iLSpeed) {
	std::cout << "running" << std::endl;
	leftSpeed = iLSpeed;
	rightSpeed = iRSpeed;
	AddParallel(new runRightMotor(rightSpeed));
	AddParallel(new runLeftMotor(leftSpeed));
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
