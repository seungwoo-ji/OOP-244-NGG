/* ------------------------------------------------------
Final Project Milestone 5
Module: Car
Filename: Car.h
Version 1.0
Author Seung Woo Ji
Student Number 116376195
Email swji1@myseneca.ca
Revision History
-----------------------------------------------------------
Date Reason
2020/3/9	Preliminary release
2020/4/01   Update for milestone #5
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef _SDDS_CAR_H
#define _SDDS_CAR_H

#include "Vehicle.h"

namespace sdds
{
	class Car : public Vehicle
	{
		bool m_cwash;

	public:
		Car();
		Car(const char* lplate, const char* mkmodel);
		Car(const Car& src) = delete;
		Car& operator=(const Car& src) = delete;
		std::istream& read(std::istream& istr = std::cin);
		std::ostream& write(std::ostream& ostr = std::cout) const;
	};
}
#endif // !_SDDS_CAR_H
