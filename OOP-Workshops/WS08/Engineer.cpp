/***********************************************************************
// OOP244 Workshop 8: Virtual Functions
// File: Engineer.cpp
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
#include <cstring>
#include "Engineer.h"

using namespace std;

namespace sdds
{
	Engineer::Engineer()
	{
		m_esalary = 0;
		m_ewhours = 0;
		m_level = 0;
	}

	Engineer::Engineer(double esalary, int ewhours, int level)
	{
		if (esalary <= 0 || ewhours <= 0 || level <= 0  || level > MAX_LEVEL)
		{
			*this = Engineer();
		}
		else
		{
			m_level = level;
			m_ewhours = ewhours;

			setSalary(esalary);
		}
	}

	void Engineer::setSalary(double esalary)
	{
		m_esalary = m_level == MAX_LEVEL ? esalary + 3000 : esalary;
	}

	bool Engineer::workHours()
	{
		return m_ewhours == MIN_HOURS;
	}

	void Engineer::bonus()
	{
		m_esalary = !workHours() && m_level == MAX_LEVEL ? 1.1 * m_esalary : 1.05 * m_esalary;
	}

	ostream& Engineer::display(ostream& os) const
	{
		if (m_esalary <= 0 || m_ewhours <= 0 || m_level <= 0 || m_level > MAX_LEVEL)
		{
			os << "Engineer is not initiated yet" << endl;
		}
		else
		{
			os << "Engineer details" << endl;
			os << "level: " << m_level << endl;
			os.setf(ios::fixed);
			os.precision(2);
			os << "Salary: " << m_esalary << endl;
			os.unsetf(ios::fixed);
			os << "Working hours: " << m_ewhours << endl;
		}

		return os;
	}
}	