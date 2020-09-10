/* ------------------------------------------------------
Final Project Milestone 6
Module: Motorcycle
Filename: Motorcycle.cpp
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
#define _CRT_SECURE_NO_WARNINGS

#include "Motorcycle.h"
#include "Utils.h"

using namespace std;

namespace sdds
{
	Motorcycle::Motorcycle()
	{
		m_sidecar = false;
	}

	Motorcycle::Motorcycle(const char* lplate, const char* mkmodel) : Vehicle(lplate, mkmodel)
	{
			m_sidecar = false;
	}

	istream& Motorcycle::read(istream& istr)
	{
		if (isCsv())
		{
			Vehicle::read(istr);
			istr >> m_sidecar;
			if (istr.fail()) 
			{
				m_sidecar = false; // to satisfy the invalid empty state checkpoint for write function
			}
			istr.ignore(1000, '\n');
		}
		else
		{
			cout << endl;
			cout << "Motorcycle information entry" << endl;
			Vehicle::read(istr);
			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";

			m_sidecar = confirm(istr);
		}

		return istr;
	}

	ostream& Motorcycle::write(ostream& ostr) const
	{
		if (isEmpty() && m_sidecar == false)
		{
			ostr << "Invalid Motorcycle Object" << endl;
		}
		else
		{
			if (isCsv())
			{
				ostr << "M,";
				Vehicle::write(ostr);
				ostr << m_sidecar << endl;
			}
			else
			{
				ostr << "Vehicle type: Motorcycle" << endl;
				Vehicle::write(ostr);

				if (m_sidecar)
				{
					ostr << "With Sidecar" << endl;
				}
			}
		}

		return ostr;
	}
}