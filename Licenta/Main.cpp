/*
	Author: Siman Marius Sorin
	All intellectual right reserved
	You are allow to use this code only if you specify the source
*/
#include "Main.h"

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