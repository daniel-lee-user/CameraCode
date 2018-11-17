/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include "Joystick.h"
#include "WPILib.h"
#include "Commands/shoot.h"

class OI {
private:
	Joystick* rightMotorStick;
	Joystick* leftMotorStick;
	Button* shooterButton;
	Button* runLeftRight;
	Button* PIDShootButton;

public:
	OI();
	~OI();
	Joystick* getRightMotorStick();
	Joystick* getLeftMotorStick();

};
