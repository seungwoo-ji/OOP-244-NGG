/***********************************************************************
// OOP244 Workshop 7: Derived Classes & Custom I/O Operators
// File: Vehicle.cpp
// Version 1.0
// Date	2020/03/10
// Author Seung Woo Ji
// Student Number 116376195
// Email swji1@myseneca.ca
// Description
// Includes the definitions for the member functions of the objects and helper functions.
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "Vehicle.h"

using namespace std;

namespace sdds
{
	Vehicle::Vehicle()
	{
		m_speed = 0;
		m_noOfSeats = 0;
	}
	
	Vehicle::Vehicle(int speed, int noOfSeats)
	{
		if (speed < MIN_SPEED || noOfSeats <= 0)
		{
			*this = Vehicle();
		}
		else
		{
			m_speed = speed;
			m_noOfSeats = noOfSeats;
		}
	}
	
	bool Vehicle::finetune()
	{
		bool result = true;

		if (m_speed > MAX_SPEED)
		{
			m_speed = MIN_SPEED;
		}
		else
		{
			cout << "The car cannot be tuned" << endl;
			result = false;
		}

		return result;
	}

	bool Vehicle::isEmpty() const
	{
		return m_speed == 0 && m_noOfSeats == 0;
	}
	
	ostream& Vehicle::display(ostream& os) const
	{
		if (isEmpty())
		{
			os << "This Car is not initiated" << endl;
		}
		else
		{
			os << "|" << m_speed << "|" << m_noOfSeats << endl;

			if (m_speed > MAX_SPEED)
			{
				os << "Car has to be fine tuned for speed limit" << endl;
			}
		}
		
		return os;
	}
	
	istream& Vehicle::input(istream& in)
	{
		int tempSpeed;
		int tempNoOfSeats;

		cout << "Enter the Vehicle`s speed: ";
		in >> tempSpeed;

		cout << "Enter no of seats: ";
		in >> tempNoOfSeats;

		*this = Vehicle(tempSpeed, tempNoOfSeats);
		
		return in;
	}

	ostream& operator<<(ostream& os, const Vehicle& v)
	{
		return v.display(os);
	}

	istream& operator>>(istream& in, Vehicle& v)
	{
		return v.input(in);
	}
}