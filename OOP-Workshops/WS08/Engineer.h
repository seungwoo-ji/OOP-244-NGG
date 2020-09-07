/***********************************************************************
// OOP244 Workshop 8: Virtual Functions
// File: Engineer.h
// Version 1.0
// Date	2020/03/24
// Author Seung Woo Ji
// Student Number 116376195
// Email swji1@myseneca.ca
// Description
// Includes the definitions for the member functions of the class and its helper functions.
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef _SDDS_ENGINEEER_H
#define _SDDS_ENGINEEER_H

#include "Employee.h"

namespace sdds
{
	const int MIN_HOURS = 5;
	const int MAX_LEVEL = 4;

	class Engineer : public Employee
	{
		double m_esalary;
		int m_ewhours;
		int m_level;

	public:
		Engineer();
		Engineer(double esalary, int ewhours, int level);
		void setSalary(double esalary);
		bool workHours();
		void bonus();
		std::ostream& display(std::ostream& os) const;
	};
}
#endif // !_SDDS_ENGINEEER_H
