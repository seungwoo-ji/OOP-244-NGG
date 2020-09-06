/***********************************************************************
// OOP244 Workshop 5: Operator Overloading
// File: Engine.h
// Version 1.0
// Date	2020/02/11
// Author Seung Woo Ji
// Student Number 116376195
// Email swji1@myseneca.ca
// Description
// Includes safeguards, object declarations, and their member 
// function protoptypes.
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_Engine_H_
#define SDDS_Engine_H_

namespace sdds
{
	const int MAX_LENGTH_E_TYPE = 30;

	class Engine
	{
		double e_size;
		char e_type[MAX_LENGTH_E_TYPE + 1];

	public:
		Engine();
		Engine(const char* type, double size);
		double get() const;
		void display() const;
	};
}
#endif