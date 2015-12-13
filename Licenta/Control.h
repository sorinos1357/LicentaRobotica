/*
	Author: Siman Marius Sorin
	All intellectual right reserved
	You are allow to use this code only if you specify the source
*/
#ifndef CONTROL_H
#define CONTROL_H

#include "Arduino.h"

void MoveForward();
void MoveBackward();
void TurnLeft();
void TurnRight();
int DistanceFront();
int DistanceLeft();
int DistanceRight();
void SetupMotors();

#endif