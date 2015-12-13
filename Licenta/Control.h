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