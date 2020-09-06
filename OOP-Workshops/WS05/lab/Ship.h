/***********************************************************************
// OOP244 Workshop 5: Operator Overloading
// File: Ship.h
// Version 1.0
// Date	2020/02/11
// Author Seung Woo Ji
// Student Number 116376195
// Email swji1@myseneca.ca
// Description
// Includes safeguards, object declarations, and their member
// function protoptypes.
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_Ship_H_
#define SDDS_Ship_H_

#include "Engine.h"

namespace sdds
{
	const int MAX_LENGTH_S_TYPE = 6;
	const int MAX_NUM_ENGINES = 10;
	
	class Ship
	{
		char s_type[MAX_LENGTH_S_TYPE + 1];
		Engine engines[10];
		int numEngines;

	public:
		Ship();
		Ship(const char* type, Engine engines[], int numEngines);
		bool empty() const;
		float calculatePower() const;
		void display() const;
		Ship& operator+=(Engine e);
		friend bool operator==(const Ship& left, const Ship& right);
	};

	bool operator<(const Ship& left, double right);
}
#endif