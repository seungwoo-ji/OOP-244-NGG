/* ------------------------------------------------------
Final Project Milestone 6
Module: Motorcycle
Filename: Motorcycle.h
Version 1.0
Author Seung Woo Ji
Student Number 116376195
Email swji1@myseneca.ca
Revision History
-----------------------------------------------------------
Date Reason
2020/3/9	Preliminary release
2020/4/01   Update for milestone #5
2020/4/10   Update for milestone #6
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef _SDDS_MOTORCYCLE_H
#define _SDDS_MOTORCYCLE_H

#include "Vehicle.h"

namespace sdds
{
	class Motorcycle : public Vehicle
	{
		bool m_sidecar;

	public:
		Motorcycle();
		Motorcycle(const char* lplate, const char* mkmodel);
		Motorcycle(const Motorcycle& src) = delete;
		Motorcycle& operator=(const Motorcycle& src) = delete;
		std::istream& read(std::istream& istr = std::cin);
		std::ostream& write(std::ostream& ostr = std::cout) const;
	};
}
#endif // !_SDDS_MOTORCYCLE_H
