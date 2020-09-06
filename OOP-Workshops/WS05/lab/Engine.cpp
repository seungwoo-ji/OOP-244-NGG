/***********************************************************************
// OOP244 Workshop 5: Operator Overloading
// File: Engine.cpp
// Version 1.0
// Date	2020/02/11
// Author Seung Woo Ji
// Student Number 116376195
// Email swji1@myseneca.ca
// Description
// Includes the definitions for the member functions of the objects.
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Engine.h"

using namespace std;

namespace sdds
{
	// constructor to set the object in a safe empty state
	Engine::Engine()
	{
		e_size = 0;
		e_type[0] = '\0';
	}

	// overloaded constructor to set the object with the client code
	Engine::Engine(const char* type, double size)
	{
		if (strlen(type) == 0 || strlen(type) > MAX_LENGTH_E_TYPE || size <= 0)
		{
			Engine();
		}
		else
		{
			strcpy(e_type, type);
			e_size = size;
		}
	}

	// returning the size of the engine
	double Engine::get() const
	{
		return e_size;
	}

	// displaying the size and the type of the engine
	void Engine::display() const
	{
		cout << e_size << " liters - " << e_type << endl;
	}
}