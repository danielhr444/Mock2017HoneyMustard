/*
 * Arm.cpp
 *      Author: Thomas Le Nguyen
 */

#include <Commands/MoveArmVertical.h>
#include "../RobotMap.h"
#include <Subsystems/Arm.h>
#include <WPILIB.h>
#include <iostream>

Arm::Arm() : Subsystem("Arm"), arm(0), armHeight(0), out(false), verticalArm(new CANTalon(ARM_VERTICAL)),
horizontalArm(new CANTalon(ARM_HORIZONTAL))
{

}

void Arm::InitDefaultCommand()
{
	SetDefaultCommand(new MoveArmVertical());
}

void Arm::moveUpAndDown(double moveValue)
{
	// if joy stick is remoted forward
	// then elevate arm up
	// if joy stick is remoted downward
	// then elevate arm down
	// if arm is static
	// don't do anything with arm height
	verticalArm->Set(moveValue);
}

void Arm::pushArmHorizontal(double moveValue)
{
	// if button is being pressed down
	// then push out arm
	// if button is not being pressed out AND is out
	// then pull arm back in
	// else keep arm in
	// basically leave it static
	horizontalArm->Set(moveValue);
}




