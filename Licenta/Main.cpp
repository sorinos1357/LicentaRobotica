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