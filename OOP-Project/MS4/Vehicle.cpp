/* ------------------------------------------------------
Final Project Milestone 4
Module: Vehicle
Filename: Vehicle.cpp
Version 1.0
Author Seung Woo
Student Number 116376195
Email swji1@myseneca.ca
Revision History
-----------------------------------------------------------
Date Reason
2020/3/9	Preliminary release
2020/3/25	Update for milestone #4
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <cctype>
#include "Vehicle.h"


using namespace std;

namespace sdds
{
	Vehicle::Vehicle()
	{
		 m_mkmodel = nullptr;
		setEmpty();
	}

	Vehicle::Vehicle(const char* lplate, const char* mkmodel)
	{
		if (lplate == nullptr || lplate[0] == '\0' || strlen(lplate) > MAX_LENGTH_PLATE || mkmodel == nullptr || mkmodel[0] == '\0' || strlen(mkmodel) <= MIN_LENGTH_MODEL || strlen(mkmodel) > MAX_LENGTH_MODEL)
		{
			m_mkmodel = nullptr;
			setEmpty();
		}
		else
		{
			m_mkmodel = nullptr;
	
			setLicensePlate(lplate); 
			setMakeModel(mkmodel);
			setParkingSpot();
		}
	}

	Vehicle::~Vehicle()
	{
		delete[] m_mkmodel;
		m_mkmodel = nullptr;
	}

	void Vehicle::setEmpty()
	{
		delete[] m_mkmodel; // delete the dynamic memory if found
		m_lplate[0] = '\0';
		m_mkmodel = nullptr;
		m_psnum = -1;
	}

	bool Vehicle::isEmpty() const
	{
		return m_lplate[0] == '\0' && m_mkmodel == nullptr && m_psnum == -1;
	}

	const char* Vehicle::getLicensePlate() const
	{
		return m_lplate;
	}

	const char* Vehicle::getMakeModel() const
	{
		return m_mkmodel;
	}

	void Vehicle::setMakeModel(const char* mkmodel)
	{	
		if (mkmodel == nullptr || mkmodel[0] == '\0' || strlen(mkmodel) < MIN_LENGTH_MODEL || strlen(mkmodel) > MAX_LENGTH_MODEL)
		{
			setEmpty();
		}
		else
		{
			delete[] m_mkmodel;
			m_mkmodel = new char[strlen(mkmodel) + 1];
			strcpy(m_mkmodel, mkmodel);
		}
	}

	void Vehicle::setLicensePlate(const char* lplate)
	{
		if (lplate == nullptr || lplate[0] == '\0' || strlen(lplate) > MAX_LENGTH_PLATE)
		{
			setEmpty();
		}
		else
		{
			for (int i = 0; i < MAX_LENGTH_PLATE; ++i)
			{
				m_lplate[i] = toupper(lplate[i]);
			}
		}
	}

	int Vehicle::getParkingSpot() const
	{
		return m_psnum;
	}

	void Vehicle::setParkingSpot(int psnum)
	{
		if (psnum < 0)
		{
			setEmpty();
		}
		else
		{
			m_psnum = psnum;
		}
	}

	bool Vehicle::operator==(const char* lplate) const
	{
		bool result = true;
		int lenLhs = strlen(m_lplate);
		int lenRhs = strlen(lplate);

		if (lenLhs == lenRhs)
		{
			for (int i = 0; i < lenLhs && result; ++i)
			{
				result = tolower(m_lplate[i]) == tolower(lplate[i]);
			}
		}
		else
		{
			result = false;
		}

		return result;
	}

	bool Vehicle::operator==(const Vehicle& rhs) const
	{
		return *this == rhs.m_lplate;
	}

	istream& Vehicle::read(istream& istr)
	{
		int psnum = 0;
		char lplate[50] = "";
		char mkmodel[100] = "";

		if (isCsv())
		{
			istr >> psnum;
			istr.ignore();

			istr.get(lplate, MAX_LENGTH_PLATE + 1, ',');
			istr.ignore(1000, ',');

			istr.get(mkmodel, MAX_LENGTH_MODEL + 1, ',');
			istr.ignore(1000, ',');
		}
		else
		{
			cout << "Enter Licence Plate Number: ";
			istr >> lplate;

			while (strlen(lplate) > MAX_LENGTH_PLATE)
			{
				istr.ignore(1000, '\n');
				cout << "Invalid Licence Plate, try again: ";
				istr >> lplate;
			}

			cout << "Enter Make and Model: ";
			istr >> mkmodel;

			while (strlen(mkmodel) < MIN_LENGTH_MODEL || strlen(mkmodel) > MAX_LENGTH_MODEL)
			{
				istr.ignore(1000, '\n');
				cout << "Invalid Make and model, try again: ";
				istr >> mkmodel;
			}
		}

		if (istr.fail())
		{
			istr.clear();
			istr.ignore(1000, '\n');

			setEmpty();
		}
		else
		{	
			setLicensePlate(lplate);
			setMakeModel(mkmodel);
			setParkingSpot(psnum);
		}

		return istr;
	}

	ostream& Vehicle::write(ostream& ostr) const
	{
		if (isEmpty())
		{
			ostr << "Invalid Vehicle Object" << endl;
		}
		else
		{
			if (isCsv())
			{
				ostr << m_psnum << "," << m_lplate << "," << m_mkmodel << ",";
			}
			else
			{
				ostr << "Parking Spot Number: ";

				if (m_psnum == 0)
				{
					ostr << "N/A" << endl;
				}
				else
				{
					ostr << m_psnum << endl;
				}

				ostr << "Licence Plate: " << m_lplate << endl;
				ostr << "Make and Model: " << m_mkmodel << endl;
			}
		}

		return ostr;
	}
}