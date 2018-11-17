/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "shooterSubsystem.h"
#include "../RobotMap.h"
#include "../Commands/ExampleCommand.h"

shooterSubsystem::shooterSubsystem() : Subsystem("ShooterSubsystem"), shooterMotor(new TalonSRX(kShooterMotor)) {
	shooterMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative,0,10);
	shooterMotor->SetInverted(false);
}

void shooterSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ExampleCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void shooterSubsystem::shooterSpeed(double motorSpeed) {
	shooterMotor->Set(ControlMode::PercentOutput, motorSpeed);
}
void shooterSubsystem::resetEncoders() {
	shooterMotor->SetSelectedSensorPosition(0,0,10);
}
double shooterSubsystem::getSpeed() {
	return shooterMotor->GetSensorCollection().GetPulseWidthVelocity()*1/(4096 * 10);
}

