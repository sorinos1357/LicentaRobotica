/*
	Author: Siman Marius Sorin
	All intellectual right reserved
	You are allow to use this code only if you specify the source
*/
#include <Main.h>
#include <Debug.h>
#include <Control.h>

#define _DEBUG

void SetupDebug()
{
#ifdef _DEBUG
	Debug::Active(true);
	gMap[10][13] = 1;
	gMap[10][15] = 1;
	gMap[10][16] = 1;
	gMap[10][17] = 1;
	gMap[10][18] = 1;	
#endif
}

void setup()
{
	Serial.println("Start setup.");
 	Serial.begin(9600);
 	
 	SetupDebug();
 	Debug::Println("Debug ready.");
 	
 	SetupMotors();
 	Debug::Println("Motors ready.");

 	gCurrentPosition.x = CENTER;
 	gCurrentPosition.y = CENTER;
 	gCurrentPosition.direction = Direction::Up;


 	Debug::Println("Program starts in 5 seconds.");
 	delay(5 * SECOND);
}

/*
	Return true if i found the room border after i surround an object
	Time: O(MAP_SIZE / 2)
*/
boolean CheckRoomBorder()
{
	Debug::Println(" -> CheckRoomBorder");

	boolean onTheLine = false;
	int intersections = 0;
	int position = CENTER + 1;

	while(position < MAP_SIZE)
	{
		if(!gMap[CENTER][position])
		{
			if(onTheLine)
			{
				onTheLine = false;
				++intersections;
			}
		}
		else if(!onTheLine)
		{
			if(gMap[CENTER][position - 1])
			{
				onTheLine = true;
			}
			else
			{
				++intersections;
			}		
		}

		++position;
	}

	Debug::Print("Intersections: ");
	Debug::Println(intersections);

	Debug::Println(" <- CheckRoomBorder");
	return 1 == (intersections % 2);
}

/*
	Move the robot to surround the object in front of him in search for the targetPoint
	and return the topmost point of the object
*/
void SurroundObjectToPoint(__in const Position& targetPosition, __out Position& topmostPosition)
{
	Debug::Println(" -> SurroundObjectToPoint");

	TurnRight();

	if(-1 != DistanceRight())
	{
		TurnRight();
	}

	do
	{
		if(-1 == DistanceLeft())
		{
			TurnLeft();
			MoveForward();
		}
		else if(-1 == DistanceFront())
		{
			MoveForward();
		}
		else
		{
			TurnRight();
		}

		if(gCurrentPosition.y < topmostPosition.y)
		{
			topmostPosition = gCurrentPosition;
		}
	}while(targetPosition != gCurrentPosition);

	Debug::Println(" <- SurroundObjectToPoint");
}

/*
	Move the robot as up as possible
*/
void GoUp()
{
	Turn(Direction::Up);
	while(-1 != DistanceFront())
	{
		MoveForward();
	}
}

void FindRoomBorder()
{
	Debug::Println(" -> FindRoomBorder");

	Position topPoint;
	do
	{
		GoUp();
		SurroundObjectToPoint(gCurrentPosition, topPoint);
		
		if(true == CheckRoomBorder())
		{
			break;
		}

		SurroundObjectToPoint(topPoint, topPoint);

	}while(true);
	
	Debug::Println(" <- FindRoomBorder");
}

void loop() 
{
	Serial.println("Result of CheckRoomBorder test: ");
	delay(10000);
}