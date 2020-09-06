/***********************************************************************
// OOP244 Workshop 4: Constructors
// File Saiyan.h
// Version 1.0
// Date	2020/02/04
// Author Seung Woo Ji
// Student Number 116376195
// Email swji1@myseneca.ca
// Description
// Includes safeguards, object declarations, and their member function protoptypes.
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_Saiyan_H_
#define SDDS_Saiyan_H_

namespace sdds
{
	class Saiyan
	{
		char m_name[30 + 1];
		int m_dob;
		int m_power;
		bool m_super;

	public:
		Saiyan();
		Saiyan(const char* name, int dob, int power);
		bool isSuper() const;
		bool isValid() const;
		void setEmpty();
		void display() const;
		void set(const char* name, int dob, int power, bool super = false);
		bool hasLost(const Saiyan& other) const;
	};
}
#endif

