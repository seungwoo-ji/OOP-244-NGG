/* ------------------------------------------------------
Final Project Milestone 5
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
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "Motorcycle.h"

using namespace std;

namespace sdds
{
	Motorcycle::Motorcycle()
	{
		m_sidecar = false;
	}

	Motorcycle::Motorcycle(const char* lplate, const char* mkmodel) : Vehicle(lplate, mkmodel)
	{
		/*if (lplate == nullptr || lplate[0] == '\0' || strlen(lplate) > MAX_LENGTH_PLATE || mkmodel == nullptr || mkmodel[0] == '\0' || strlen(mkmodel) <= MIN_LENGTH_MODEL || strlen(mkmodel) > MAX_LENGTH_MODEL)
		{
			m_sidecar = false;
		}
		else
		{*/
			m_sidecar = false;
		//}
	}

	istream& Motorcycle::read(istream& istr)
	{
		if (isCsv())
		{
			Vehicle::read(istr);
			istr >> m_sidecar;
			if (istr.fail()) // reset the istr object and clear the buffer when failed
			{
				istr.clear();
				m_sidecar = false; // to satisfy the invalid empty state checkpoint for write function
			}
			istr.ignore(1000, '\n');
		}
		else
		{
			char select[5];
			bool flag = true;

			cout << endl;
			cout << "Motorcycle information entry" << endl;
			Vehicle::read(istr);
			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";

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
					m_sidecar = true;
					flag = false;
				}
				else if (!strcmp(select, "n") || !strcmp(select, "N"))
				{
					m_sidecar = false;
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