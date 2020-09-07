/***********************************************************************
// OOP244 Workshop 8: Virtual Functions
// File: Doctor.h
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
#ifndef _SDDS_DOCTOR_H
#define _SDDS_DOCTOR_H

#include "Employee.h"

namespace sdds 
{
	const int MIN_W_HOURS = 6;
	const int MAX_CHAR = 20;

	class Doctor : public Employee
	{
		char m_type[MAX_CHAR + 1];
		double m_salary;
		int m_whours;
		bool m_specialist;

	public:
		Doctor();
		Doctor(const char* type, double salary, int whours, bool specialist = false);
		void setSalary(double salary);
		bool workHours();
		void bonus();
		std::ostream& display(std::ostream& os) const;
	};
}

#endif // !_SDDS_DOCTOR_H
