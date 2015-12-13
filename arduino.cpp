/*
	Author: Siman Marius Sorin
	All intellectual right reserved
	You are allow to use this code only if you specify the source
*/
#include <Main.h>
#include <Debug.h>
#include <Control.h>

#define _DEBUG

boolean gMap[MAP_SIZE][MAP_SIZE];
Position gCurrentPosition;

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


 	Debug::Println("Program starts in 5 seconds.");
 	delay(5 * SECOND);
}

/*
	Check if i found the room border
	Time: O(MAP_SIZE / 2)
*/
boolean CheckRoomBorder()
{
	Debug::Println(" -> CheckRoomMargin");

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

	Debug::Println(intersections);

	Debug::Println(" <- CheckRoomMargin");
	return 1 == (intersections % 2);
}

void SurroundObject()
{
	Debug::Println(" -> SurroundObject");

	Position begin = gCurrentPosition;
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
	}while(begin != gCurrentPosition);

	Debug::Println(" <- SurroundObject");
}

void FindRoomBorder()
{
	Debug::Println(" -> FindRoomBorder");


	Debug::Println(" <- FindRoomBorder");
}

void loop() 
{
	Serial.println("Result of CheckRoomMargin test: ");
	delay(10000);
}