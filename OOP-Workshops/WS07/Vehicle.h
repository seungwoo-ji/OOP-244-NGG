/**********************************************************************
// OOP244 Workshop 7: Derived Classes & Custom I/O Operators
// File: Vehicle.h
// Version 1.0
// Date	2020/03/10
// Author Seung Woo Ji
// Student Number 116376195
// Email swji1@myseneca.ca
// Description
// Includes safeguards, object declarations, as well as object member
// function and helper function prototypes
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H

#include <iostream>

namespace sdds
{
	const int MIN_SPEED = 100;
	const int MAX_SPEED = 140;

	class Vehicle
	{
		int m_speed;
		int m_noOfSeats;

	public:
		Vehicle();
		Vehicle(int speed, int noOfSeats);
		bool finetune();
		bool isEmpty() const;
		std::ostream& display(std::ostream& os) const;
		std::istream& input(std::istream& in);
	};
	
	std::ostream& operator<<(std::ostream& os, const Vehicle& v);
	std::istream& operator>>(std::istream& in, Vehicle& V);

}
#endif // ! SDDS_VEHICLE_H
