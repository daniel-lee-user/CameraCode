/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/


#include "TankDriveSubsystem.h"
#include "../RobotMap.h"
#include "ctre/Phoenix.h"
#include "../Commands/TankDrive.h"

TankDriveSubsystem::TankDriveSubsystem() : Subsystem("TankDriveSubsystem"), left(new TalonSRX(kLeftMotor)), right(new TalonSRX(kRightMotor)){
	left->SetInverted(false);
	right->SetInverted(true);
}
void TankDriveSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new TankDrive());
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void TankDriveSubsystem::tankDrive(double leftSpeed, double rightSpeed) {
	left->Set(ControlMode::PercentOutput, leftSpeed);
	right->Set(ControlMode::PercentOutput, rightSpeed);
}
void TankDriveSubsystem::setRightSpeed(double rSpeed) {
	right->Set(ControlMode::PercentOutput, rSpeed);
}
void TankDriveSubsystem::setLeftSpeed(double lSpeed) {
	left->Set(ControlMode::PercentOutput, lSpeed);
}
TankDriveSubsystem::~TankDriveSubsystem() {
	if (left!= nullptr) {
		delete left;
	}
	if(right != nullptr) {
		delete right;
	}
}
