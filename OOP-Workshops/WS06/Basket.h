/**********************************************************************
// OOP244 Workshop 6: Class with a Resource
// File: Basket.h
// Version 1.0
// Date	2020/03/03
// Author Seung Woo Ji
// Student Number 116376195
// Email swji1@myseneca.ca
// Description
// Includes safeguards, object declarations, as well as object member
// function and helper function prototypes
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H

#include <iostream>

namespace sdds
{
	class Basket
	{
		char* m_fruitName;
		int m_qty;
		double m_price;
		
	public:
		Basket();
		Basket(const char* name, int qty, double price);
		Basket(const Basket& src);
		~Basket();
		void setName(const char* name);
		void setQty(int qty);
		void setPrice(double price);
		bool isempty() const;
		bool addPrice(double price);
		std::ostream& display(std::ostream& os) const;
		Basket& operator=(const Basket& src);
		bool operator==(const Basket& rhs);
		bool operator!=(const Basket& rhs);
	};

	std::ostream& operator<<(std::ostream& os, const Basket& bsk);
}
#endif