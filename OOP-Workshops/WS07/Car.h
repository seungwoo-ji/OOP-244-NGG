/**********************************************************************
// OOP244 Workshop 7: Derived Classes & Custom I/O Operators
// File: Car.h
// Version 1.0
// Date	2020/03/10
// Author Seung Woo Ji
// Student Number 116376195
// Email swji1@myseneca.ca
// Description
// Includes safeguards, class declarations, as well as object member
// function and helper function prototypes
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include "Vehicle.h"

namespace sdds
{
	const int MAX_CHAR = 20;
	const int MIN_YEAR = 2000;
	
	class Car : public Vehicle
	{
		char m_carType[MAX_CHAR + 1];
		int m_regYear;

	public:
		Car();
		Car(const char* carType, int regYear, int speed, int numOfSeats);
		void finetune();
		std::ostream& display(std::ostream& os) const;
		std::istream& input(std::istream& in);
	};

	std::ostream& operator<<(std::ostream& os, const Car& c);
	std::istream& operator>>(std::istream& in, Car& c);
}
#endif // !SDDS_CAR_H
