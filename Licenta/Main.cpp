/*
	Author: Siman Marius Sorin
	All intellectual right reserved
	You are allow to use this code only if you specify the source
*/
#include "Main.h"

boolean gMap[MAP_SIZE][MAP_SIZE];
Position gCurrentPosition;

// prefix ++ for Direction
Direction& operator++(Direction& dir)
{
 	int newDir = dir + 1;
 	if((Direction::Left + 1) == newDir)
 	{
 		newDir = Direction::Up;
 	}
 	
 	dir = static_cast<Direction>(newDir);
 	return dir;
}

// prefix -- for Direction
Direction& operator--(Direction& dir)
{
  	int newDir = dir - 1;
 	if(-1 == newDir)
 	{
 		newDir = Direction::Left;
 	}
 	
 	dir = static_cast<Direction>(newDir);
 	return dir;
}

Position::Position(int x, int y, Direction dir):
		Point(x, y),
		direction(dir)
{}

Position::Position(const Position &other):
		Point(other.x, other.y)
{
	this->direction = other.direction;
}

const Position& Position::operator=(const Position& other)
{
	this->x = other.x;
	this->y = other.y;
	this->direction = other.direction;
	return other;
}

// don't care about direction
boolean Position::operator==(const Position& other) const
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

boolean Position::operator!=(const Position& other) const
{
	return !(*this == other);
}