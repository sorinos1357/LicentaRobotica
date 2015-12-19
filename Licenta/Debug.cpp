/*
	Author: Siman Marius Sorin
	All intellectual right reserved
	You are allow to use this code only if you specify the source
*/
#include "Arduino.h"
#include "Main.h"
#include "Debug.h"

boolean Debug::m_Active = false;

void Debug::Active(boolean act)
{
	m_Active = act;
}

void Debug::PrintMap()
{
	if(!m_Active)
	{
		return;
	}

	int i,j;
	Serial.println(' ');
	for(i = 0; i < MAP_SIZE; ++i)
	{
		for(j = 0; j < MAP_SIZE; ++j)
		{
			Serial.print(gMap[i][j]);
			Serial.print(' ');
		}
		Serial.println(' ');
	}	
}

void Debug::Print(int i)
{
	if(!m_Active)
	{
		return;
	}

	Serial.print(i);
}

void Debug::Print(const char* line)
{
	if(!m_Active)
	{
		return;
	}

	Serial.print(line);
}

void Debug::Println(int i)
{
	if(!m_Active)
	{
		return;
	}

	Serial.println(i);
}

void Debug::Println(const char* line)
{
	if(!m_Active)
	{
		return;
	}

	Serial.println(line);
}