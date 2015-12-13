#ifndef DEBUG_H
#define DEBUG_H

#include "Arduino.h"

class Debug
{
public:
	static boolean m_Active;

	static void Active(boolean);
	static void Print(int);
	static void Println(int);
	static void Println(const char*);
	static void PrintMap();
};

#endif