/***********************************************************************
// OOP244 Workshop 8: Virtual Functions
// File: Doctor.cpp
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
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "Doctor.h"

using namespace std;

namespace sdds
{
	Doctor::Doctor()
	{
		m_type[0] = '\0';
		m_salary = 0;
		m_whours = 0;
		m_specialist = false;
	}

	Doctor::Doctor(const char* type, double salary, int whours, bool specialist)
	{
		if (type == nullptr || type[0] == '\0' || salary <= 0 || whours <= 0)
		{
			*this = Doctor();
		}
		else
		{
			strncpy(m_type, type, MAX_CHAR + 1);
			m_type[MAX_CHAR] = '\0';

			m_whours = whours;
			m_specialist = specialist;

			setSalary(salary);
		}
	}

	void Doctor::setSalary(double salary)
	{
		m_salary = m_specialist ? salary + 2000 : salary;
	}

	bool Doctor::workHours()
	{
		return m_whours == MIN_W_HOURS;
	}

	void Doctor::bonus()
	{
		m_salary = workHours() ? 1.05 * m_salary : 1.1 * m_salary;
	}

	ostream& Doctor::display(ostream& os) const
	{
		if (m_type == nullptr || m_type[0] == '\0' || m_salary <= 0 || m_whours <= 0)
		{
			os << "Doctor is not initiated yet" << endl;
		}
		else
		{
			os << "Doctor details" << endl;
			os << "Doctor Type: " << m_type << endl;
			
			os.setf(ios::fixed);
			os.precision(2);
			os << "Salary: " << m_salary << endl;
			os.unsetf(ios::fixed);
			os << "Working Hours: " << m_whours << endl;
		}

		return os;
	}
}

