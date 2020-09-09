/* ------------------------------------------------------
Final Project Milestone 4
Module: ReadWritable
Filename: ReadWritable.h
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
#ifndef _SDDS_READWRITABLE_H
#define _SDDS_READWRITABLE_H

#include <iostream>

namespace sdds
{
	class ReadWritable
	{
		bool m_csvalue;

	public:
		ReadWritable();
		virtual ~ReadWritable() {};
		bool isCsv() const;
		void setCsv(bool value);
		virtual std::ostream& write(std::ostream& ostr = std::cout) const = 0;
		virtual std::istream& read(std::istream& istr = std::cin) = 0;
	};

	std::ostream& operator<<(std::ostream& os, const ReadWritable& src);
	std::istream& operator>>(std::istream& is, ReadWritable& src);
}
#endif // !_SDDS_READWRITABLE_H
