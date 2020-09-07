/***********************************************************************
// OOP244 Workshop 8: Virtual Functions
// File: Employee.h
// Version 1.0
// Date	2020/03/24
// Author Seung Woo Ji
// Student Number 116376195
// Email swji1@myseneca.ca
// Description
// Includes the definitions for the member functions of the class and its helper functions.
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef _SDDS_EMPLOYEE_H
#define _SDDS_EMPLOYEE_H

#include <iostream>

namespace sdds
{
	class Employee
	{
	public:
		virtual ~Employee() {};
		virtual void setSalary(double salary) = 0;
		virtual void bonus() = 0;
		virtual bool workHours() = 0;
		virtual std::ostream& display(std::ostream& os) const = 0;
	};
}
#endif // ! _SDDS_EMPLOYEE_H