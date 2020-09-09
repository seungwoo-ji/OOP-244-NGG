/* ------------------------------------------------------
Final Project Milestone 3
Module: ReadWritable
Filename: ReadWritable.cpp
Version 1.0
Author Seung Woo
Student Number 116376195
Email swji1@myseneca.ca
Revision History
-----------------------------------------------------------
Date Reason
2020/3/9	Preliminary release
2020/3/25	Update for milestone #3
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include "ReadWritable.h"

using namespace std;

namespace sdds
{
	ReadWritable::ReadWritable()
	{
		m_csvalue = false;
	}

	bool ReadWritable::isCsv() const
	{
		return m_csvalue;
	}

	void ReadWritable::setCsv(bool value)
	{
		m_csvalue = value;
	}

	ostream& operator<<(ostream& ostr, const ReadWritable& src)
	{
		return src.write(ostr);
	}

	istream& operator>>(istream& istr, ReadWritable& src)
	{
		return src.read(istr);
	}

}