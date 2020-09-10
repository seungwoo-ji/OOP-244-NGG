/* ------------------------------------------------------
Final Project Milestone 6
Module: Car
Filename: Car.cpp
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

#include "Car.h"
#include "Utils.h"

using namespace std;

namespace sdds
{
	Car::Car()
	{
		m_cwash = false;
	}

	Car::Car(const char* lplate, const char* mkmodel) : Vehicle(lplate, mkmodel)
	{
			m_cwash = false;
	}

	istream& Car::read(istream& istr)
	{
		if (isCsv())
		{
			Vehicle::read(istr);
			istr >> m_cwash;
			if (istr.fail()) 
			{
				m_cwash = false; // to satisfy the invalid empty state checkpoint for write function
			}
			istr.ignore(1000, '\n');
		}
		else
		{

			cout << endl;
			cout << "Car information entry" << endl;
			Vehicle::read(istr);
			cout << "Carwash while parked? (Y)es/(N)o: ";

			m_cwash = confirm(istr);
		}

		return istr;
	}

	ostream& Car::write(ostream& ostr) const
	{
		if (isEmpty() && m_cwash == false)
		{
			ostr << "Invalid Car Object" << endl;
		}
		else
		{
			if (isCsv())
			{
				ostr << "C,";
				Vehicle::write(ostr);
				ostr << m_cwash << endl;
			}
			else
			{
				ostr << "Vehicle type: Car" << endl;
				Vehicle::write(ostr);

				if (m_cwash)
				{
					ostr << "With Carwash" << endl;
				}
				else
				{
					ostr << "Without Carwash" << endl;
				}
			}
		}

		return ostr;
	}
}