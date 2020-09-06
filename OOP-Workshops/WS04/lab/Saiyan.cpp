/***********************************************************************
// OOP244 Workshop 4: Constructors
// File Saiyan.cpp
// Version 1.0
// Date	2020/02/04
// Author Seung Woo Ji
// Student Number 116376195
// Email swji1@myseneca.ca
// Description
// Includes the definitions for the member functions of the objects.
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
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

	// overloading constructor for Saiyan class to set up the object by user
	Saiyan::Saiyan(const char* name, int dob, int power)
	{
		set(name, dob, power);
	}

	// checking whether the character has the ability to be super saiyan
	bool Saiyan::isSuper() const
	{
		return m_super;
	}

	// checking if the object is not safe state
	bool Saiyan::isValid() const
	{
		return m_name[0] != '\0' && m_dob != 0 && m_power != 0;
	}

	// setting up the object as empty state
	void Saiyan::setEmpty()
	{
		m_name[0] = '\0';
		m_dob = 0;
		m_power = 0;
		m_super = false;
	}

	// displaying the details of the saiyans
	void Saiyan::display() const
	{
		if (isValid())
		{
			cout << m_name << endl;
			cout << "DOB: " << m_dob << " Power: " << m_power << endl;
			cout << "Super Saiyan Ability: ";
			if (m_super)
			{
				cout << "Super Saiyan.\n" << endl;
			}
			else
			{
				cout << "Not super Saiyan.\n" << endl;
			}
		}
		else
		{
			cout << "Invalid Saiyan!" << endl;
		}
	}

	// setting up the instance of saiyan class
	void Saiyan::set(const char* name, int dob, int power, bool super)
	{
		if (name == nullptr || strlen(name) == 0 || dob >= 2020 || power <= 0)
		{
			setEmpty();
		}
		else
		{
			strcpy(m_name, name);
			m_dob = dob;
			m_power = power;
			m_super = super;
		}
	}

	// checking if the battle is lost
	bool Saiyan::hasLost(const Saiyan& other) const
	{
		return isValid() && other.isValid() && m_power < other.m_power;
	}
}