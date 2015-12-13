#ifndef MAIN_H
#define MAIN_H

#include "Arduino.h"

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

	Position(int x = 0, int y = 0, Direction dir = Direction::Up):
		Point(x, y),
		direction(dir)
	{}

	Position(const Position &other):
		Point(other.x, other.y)
	{
		this->direction = other.direction;
	}

	const Position& operator=(const Position& other)
	{
		this->x = other.x;
		this->y = other.y;
		this->direction = other.direction;
		return other;
	}

	// don't care about direction
	boolean operator==(const Position& other)
	{
		if(this->x == other.x && this->y == other.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	boolean operator!=(const Position& other)
	{
		return !(*this == other);
	}
};

extern boolean gMap[MAP_SIZE][MAP_SIZE];
extern Position gCurrentPosition;

#endif