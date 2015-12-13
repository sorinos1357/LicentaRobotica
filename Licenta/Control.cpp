#include "Arduino.h"
#include "Control.h"
#include "Main.h"

void MoveForward()
{

}

void MoveBackward()
{

}

void TurnLeft()
{
	--gCurrentPosition.direction;
}

void TurnRight()
{
	++gCurrentPosition.direction;
}

int DistanceFront()
{
	return 0;
}

int DistanceLeft()
{
	return 0;
}

int DistanceRight()
{
	return 0;
}