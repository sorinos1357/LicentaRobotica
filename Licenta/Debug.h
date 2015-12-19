/*
	Author: Siman Marius Sorin
	All intellectual right reserved
	You are allow to use this code only if you specify the source
*/
#ifndef DEBUG_H
#define DEBUG_H

#include "Arduino.h"

class Debug
{
public:
	static boolean m_Active;

	static void Active(boolean);
	static void Print(int);
	static void Print(const char*);
	static void Println(int);
	static void Println(const char*);
	static void PrintMap();
};

#endif