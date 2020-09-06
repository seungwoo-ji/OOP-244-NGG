/***********************************************************************
// OOP244 Workshop 4: Constructors
// File Saiyan.h
// Version 1.0
// Date	2020/02/09
// Author Seung Woo Ji
// Student Number 116376195
// Email swji1@myseneca.ca
// Description
// Includes safeguards, object declarations, and their member function protoptypes.
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Seung Woo Ji	   Feb, 09 2020	   Completed Workshop 4 - DIY
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_Saiyan_H_
#define SDDS_Saiyan_H_

namespace sdds
{
	const int MAX_NAME = 30;

	class Saiyan
	{
		char* m_name;
		int m_dob;
		int m_power;
		bool m_super;
		int m_level;

	public:
		Saiyan();
		Saiyan(const char* name, int dob, int power);
		~Saiyan();
		bool isSuper() const;
		bool isValid() const;
		bool hasLost(Saiyan& other);
		void setEmpty();
		void display() const;
		void set(const char* name, int dob, int power, int level = 0, bool super = false);
		void powerup();
		void powerdown();
	};
}
#endif

