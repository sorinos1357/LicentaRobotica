/*
	Author: Siman Marius Sorin
	All intellectual right reserved
	You are allow to use this code only if you specify the source
*/
#include "Arduino.h"
#include "Control.h"
#include "Main.h"

const int MOTOR1_PIN1 				= 3;
const int MOTOR1_PIN2 				= 5;

const int MOTOR2_PIN1 				= 6;
const int MOTOR2_PIN2 				= 9;

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

void SetupMotors()
{
	pinMode(MOTOR1_PIN1, OUTPUT);
 	pinMode(MOTOR1_PIN2, OUTPUT);
 	pinMode(MOTOR2_PIN1, OUTPUT);
 	pinMode(MOTOR2_PIN2, OUTPUT);
}

void Turn(__in const Direction direction)
{
	 while(direction != gCurrentPosition.direction)
	 {
	 	TurnRight();
	 }
}

/*void go(int speedLeft, int speedRight)
{
	if (speedLeft > 0)
	{
   		analogWrite(MOTOR1_PIN1, speedLeft);
   		analogWrite(MOTOR1_PIN2, 0);
 	}
 	else
 	{
   		analogWrite(MOTOR1_PIN1, 0);
   		analogWrite(MOTOR1_PIN2, -speedLeft);
 	}

 	if (speedRight > 0)
 	{
		analogWrite(MOTOR2_PIN1, speedRight);
   		analogWrite(MOTOR2_PIN2, 0);
 	}
 	else 
 	{
   		analogWrite(MOTOR2_PIN1, 0);
   		analogWrite(MOTOR2_PIN2, -speedRight);
 	}
}*/