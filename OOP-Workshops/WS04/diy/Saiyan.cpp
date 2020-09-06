/***********************************************************************
// OOP244 Workshop 4: Constructors
// File Saiyan.cpp
// Version 1.0
// Date	2020/02/09
// Author Seung Woo Ji
// Student Number 116376195
// Email swji1@myseneca.ca
// Description
// Includes the definitions for the member functions of the objects.
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Seung Woo Ji	   Feb, 09 2020	   Completed Workshop 4 - DIY
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Saiyan.h"

using namespace std;

namespace sdds
{
	// constructor for Saiyan class to set up the object as empty state
	Saiyan::Saiyan()
	{
		setEmpty();
	}

	// overloading constructor for Saiyan class to set up the object by given parameters
	Saiyan::Saiyan(const char* name, int dob, int power)
	{
		m_name = nullptr;
		set(name, dob, power);
	}

	// destructor to deallocate the dynamic memory
	Saiyan::~Saiyan()
	{
		delete[] m_name;
		m_name = nullptr;
	}

	// checking whether the character has the ability to be super saiyan
	bool Saiyan::isSuper() const
	{
		return m_super;
	}

	// checking if the object is not safe state
	bool Saiyan::isValid() const
	{
		return m_name != nullptr && m_dob != 0 && m_power != 0 && m_level != -1;
	}

	// checking if the battle is lost
	bool Saiyan::hasLost(Saiyan& other)
	{
		bool result = false;

		if (isValid() && other.isValid())
		{
			powerup();
			other.powerup();

			if (m_power < other.m_power)
			{
				result = true;
			}

			powerdown();
			other.powerdown();
		}
		return result;
	}

	// setting up the object as empty state
	void Saiyan::setEmpty()
	{
		m_name = nullptr;
		m_dob = 0;
		m_power = 0;
		m_super = false;
		m_level = -1;
	}

	// displaying the details of the saiyans
	void Saiyan::display() const
	{
		if (isValid())
		{
			cout << m_name << endl;
			cout << "DOB: " << m_dob << " Power: " << m_power << endl;
			cout << "Super Saiyan Ability: " << (isSuper() ? "Super Saiyan." : "Not super Saiyan.\n") << endl;

			if (m_level > 0)
			{
				cout << "Super Saiyan level is: " << m_level << endl;
			}
		}
		else
		{
			cout << "Invalid Saiyan!" << endl;
		}
	}

	// setting up the instance of saiyan class
	void Saiyan::set(const char* name, int dob, int power, int level, bool super)
	{
		if (m_name != nullptr) // Possible memory leak in set function, if we call set a second time with invalid params
		{
			delete[] m_name;
		}
		
		if (name == nullptr || strlen(name) == 0 || strlen(name) > MAX_NAME || dob >= 2020 || power <= 0 || level < 0)
		{				
			setEmpty();
		}
		else
		{
			/*if (m_name != nullptr)
			{
				delete[] m_name;
			}*/

			m_name = new char[strlen(name) + 1];

			strcpy(m_name, name);

			m_dob = dob;
			m_power = power;
			m_super = super;
			m_level = level;
		}
	}

	// powering up the saiyan by level + 1
	void Saiyan::powerup()
	{
		if (m_super)
		{
			m_power = m_power * (m_level + 1);
		}
	}

	// optional: powering down the saiyan by level + 1
	void Saiyan::powerdown()
	{
		if (m_super)
		{
			m_power = m_power / (m_level + 1);
		}
	}

}