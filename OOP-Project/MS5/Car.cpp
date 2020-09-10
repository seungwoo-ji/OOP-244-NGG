/* ------------------------------------------------------
Final Project Milestone 5
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
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "Car.h"

using namespace std;

namespace sdds
{
	Car::Car()
	{
		m_cwash = false;
	}

	Car::Car(const char* lplate, const char* mkmodel) : Vehicle(lplate, mkmodel)
	{
		/*if (lplate == nullptr || lplate[0] == '\0' || strlen(lplate) > MAX_LENGTH_PLATE || mkmodel == nullptr || mkmodel[0] == '\0' || strlen(mkmodel) <= MIN_LENGTH_MODEL || strlen(mkmodel) > MAX_LENGTH_MODEL)
		{
			m_cwash = false;
		}
		else
		{*/
			m_cwash = false;
		//}
	}

	istream& Car::read(istream& istr)
	{
		if (isCsv())
		{
			Vehicle::read(istr);
			istr >> m_cwash;
			if (istr.fail()) // reset the istr object and clear the buffer when failed
			{
				istr.clear();
				m_cwash = false; // to satisfy the invalid empty state checkpoint for write function
			}
			istr.ignore(1000, '\n');
		}
		else
		{
			char select[5];
			bool flag = true;

			cout << endl;
			cout << "Car information entry" << endl;
			Vehicle::read(istr);
			cout << "Carwash while parked? (Y)es/(N)o: ";

			do
			{
				istr.getline(select, 5);
				if (istr.fail())
				{
					istr.clear();
					istr.ignore(1000, '\n');
				}

				if (!strcmp(select, "y") || !strcmp(select, "Y"))
				{
					m_cwash = true;
					flag = false;
				}
				else if (!strcmp(select, "n") || !strcmp(select, "N"))
				{
					m_cwash = false;
					flag = false;
				}
				else
				{
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				}
			} while (flag);
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