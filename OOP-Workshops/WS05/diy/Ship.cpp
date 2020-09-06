/***********************************************************************
// OOP244 Workshop 5: Operator Overloading
// File: Ship.cpp
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
#include "Ship.h"

using namespace std;

namespace sdds
{
	// constructor to set the object in a safe empty state 
	Ship::Ship()
	{
		s_type = nullptr;
		engines = nullptr;
		numEngines = 0;
	}

	// destructor to deallocate the dynamic memory
	Ship::~Ship()
	{
		delete[] engines;
		engines = nullptr;

		delete[] s_type;
		s_type = nullptr;
	}

	// overloaded constructor to set the object with the client code
	Ship::Ship(const char* type, Engine engines[], int numEngines)
	{
		if (type == nullptr || strlen(type) > MAX_LENGTH_S_TYPE || strlen(type) == 0 || numEngines <= 0)
		{
			Ship();
		}
		else
		{
			s_type = new char[strlen(type) + 1];

			strcpy(s_type, type);
			this->numEngines = numEngines;

			this->engines = new Engine[numEngines];

			for (int i = 0; i < numEngines; ++i)
			{
				this->engines[i] = engines[i];
			}
		}
	}

	// checking if the object is in a safe empty state
	bool Ship::empty() const
	{
		return s_type == nullptr && numEngines == 0;
	}

	// calculating the ship output power
	float Ship::calculatePower() const
	{
		float output = 0.0f;

		for (int i = 0; i < numEngines; ++i)
		{
			output += (float)engines[i].get() * 5;
		}
		return output;
	}

	// displaying the ship information
	void Ship::display() const
	{
		if (!empty())
		{
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << s_type << '-';
			cout.width(6);
			cout << calculatePower() << endl;

			for (int i = 0; i < numEngines; ++i)
			{
				engines[i].display();
			}

			cout.unsetf(ios::fixed);
		}
		else
		{
			cout << "No available data" << endl;
		}
	}

	// adding an engine to the array of engines
	Ship& Ship::operator+=(Engine e)
	{
		if (empty())
		{
			cout << "The ship doesn't have a type! Engine cannot be added!" << endl;
		}
		else
		{
			Engine* temp = new Engine[numEngines + 1];

			for (int i = 0; i < numEngines; ++i)
			{
				temp[i] = engines[i];
			}

			temp[numEngines] = e;
			numEngines++;

			delete[] engines;
			engines = new Engine[numEngines];

			for (int i = 0; i < numEngines; ++i)
			{
				engines[i] = temp[i];
			}

			delete[] temp;
			temp = nullptr;
		}
		return *this;
	}

	// Comparing if the left and right objects have the power
	bool operator==(const Ship& left, const Ship& right)
	{
		return left.calculatePower() == right.calculatePower();
	}

	// Comparing the total output power of the left object to the right value
	bool operator<(const Ship& left, double right)
	{
		return left.calculatePower() < right;
	}
}

