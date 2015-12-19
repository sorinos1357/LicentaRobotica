/*
	Author: Siman Marius Sorin
	All intellectual right reserved
	You are allow to use this code only if you specify the source
*/
#ifndef MAIN_H
#define MAIN_H

#include "Arduino.h"

#define __in 
#define __out 
#define __in_opt 

const int 	MAP_SIZE 				= 20;
const int 	CENTER 	 				= MAP_SIZE / 2;
const int	SECOND					= 1000;

enum Direction
{
	Up = 0,
	Right,
	Down,
	Left,
	DirectionCount
};

// prefix ++ for Direction
Direction& operator++(Direction& dir);

// prefix -- for Direction
Direction& operator--(Direction& dir);


struct Point
{
	/*
		(0,0) is the Up-Left corner
		x growth right
		y growth down
	*/
	int x;
	int y;

	Point(int x = 0, int y = 0):
		x(x),
		y(y)
	{}
};

struct Position : public Point
{
	Direction direction;

	Position(int x = 0, int y = 0, Direction dir = Direction::Up);
	Position(const Position &other);
	
	const Position& operator=(const Position& other);
	boolean operator==(const Position& other) const;

	boolean operator!=(const Position& other) const;
};

extern boolean gMap[MAP_SIZE][MAP_SIZE];
extern Position gCurrentPosition;

#endif