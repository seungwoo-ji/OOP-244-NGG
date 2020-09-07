/***********************************************************************
// OOP244 Workshop 7: Derived Classes & Custom I/O Operators
// File: Car.cpp
// Version 1.0
// Date	2020/03/10
// Author Seung Woo Ji
// Student Number 116376195
// Email swji1@myseneca.ca
// Description
// Includes the definitions for the member functions of the child class
// and helper functions.
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "Car.h"

using namespace std;

namespace sdds
{
	Car::Car()
	{
		m_carType[0] = '\0';
		m_regYear = 0;
	}

	Car::Car(const char* carType, int regYear, int speed, int noOfSeats) : Vehicle(speed, noOfSeats)
	{
		if (carType == nullptr || strlen(carType) == 0 || strlen(carType) > MAX_CHAR || regYear < MIN_YEAR || Vehicle::isEmpty())
		{
			*this = Car();
		}
		else
		{
			strcpy(m_carType, carType);
			m_regYear = regYear;
		}
	}

	void Car::finetune()
	{
		if (m_regYear < MIN_YEAR)
		{
			cout << "Car cannot be tuned and has to be scraped" << endl;
		}
		else
		{
			if (Vehicle::finetune())
			{
				cout << "This car is finely tuned to default speed" << endl;
			}
		}
	}

	ostream& Car::display(ostream& os) const
	{
		if (m_carType[0] == '\0' && m_regYear == 0)
		{
			os << "Car is not initiated yet" << endl;
		}
		else
		{
			os.width(20);
			os.setf(ios::left);
			os << m_carType;
			os.unsetf(ios::left);
			os << m_regYear;
			Vehicle::display(os);
		}

		return os;
	}

	std::istream& Car::input(std::istream& in)
	{
		char tempCarType[MAX_CHAR + 1];
		int tempRegYear;

		cout << "Enter the car type: ";
		in.getline(tempCarType, MAX_CHAR + 1);
		//in.ignore(2000, '\n'); // clear the input buffer

		cout << "Enter the car registration year: ";
		in >> tempRegYear;

		Vehicle::input(in);

		if (strlen(tempCarType) == 0 || tempRegYear < MIN_YEAR || Vehicle::isEmpty())
		{
			*this = Car();
		}
		else
		{
			strcpy(m_carType, tempCarType);
			m_regYear = tempRegYear;
		}

		return in;
	}
	std::ostream& operator<<(std::ostream& os, const Car& c)
	{
		return c.display(os);
	}
	std::istream& operator>>(std::istream& in, Car& c)
	{
		return c.input(in);
	}
}

