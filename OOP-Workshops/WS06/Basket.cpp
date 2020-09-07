/***********************************************************************
// OOP244 Workshop 6: Class with a Resource
// File: Basket.cpp
// Version 1.0
// Date	2020/03/03
// Author Seung Woo Ji
// Student Number 116376195
// Email swji1@myseneca.ca
// Description
// Includes the definitions for the member functions of the objects and helper functions.
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
#include "Basket.h"

using namespace std;

namespace sdds
{
	Basket::Basket()
	{
		m_fruitName = nullptr;
		m_qty = 0;
		m_price = 0.0;
	}
	Basket::Basket(const char* name, int qty, double price)
	{
		if (name == nullptr || strlen(name) == 0 || qty <= 0 || price <= 0.0)
		{
			m_fruitName = nullptr;
			*this = Basket();
		}
		else
		{
			setName(name);
			setQty(qty);
			setPrice(price);
		}
	}
	Basket::Basket(const Basket& src)
	{
		// directly calling the copy assignment operator
		m_fruitName = nullptr;
		*this = src;
	}
	Basket::~Basket()
	{
		delete[] m_fruitName;
		m_fruitName = nullptr;
	}
	void Basket::setName(const char* name)
	{
		if (name != nullptr && strlen(name) > 0)
		{
			m_fruitName = new char[strlen(name) + 1];
			strcpy(m_fruitName, name);
		}
		else
		{
			m_fruitName = nullptr;
		}
	}
	void Basket::setQty(int qty)
	{
		if (qty > 0)
		{
			m_qty = qty;
		}
		else
		{
			m_qty = 0;
		}
	}
	void Basket::setPrice(double price)
	{
		if (price > 0)
		{
			m_price = price;
		}
		else
		{
			m_price = 0.0;
		}
	}
	bool Basket::isempty() const
	{
		return m_fruitName == nullptr && m_qty == 0 && m_price == 0.0;
	}
	bool Basket::addPrice(double price)
	{
		bool result = false;

		if (price > 0)
		{
			m_price += price;
			result = true;
		}

		return result;
	}
	std::ostream& Basket::display(std::ostream& os) const
	{
		if (isempty())
		{
			os << "The Basket has not yet been filled" << endl;
		}
		else
		{
			os << "Basket Details" << endl;
			os << "Name: " << m_fruitName << endl;
			os << "Quantity: " << m_qty << endl;
			os.setf(ios::fixed);
			os.precision(2);
			os << "Price: " << m_price << endl;
		}

		return os;
	}
	Basket& Basket::operator=(const Basket& src)
	{
		// checking for self-assignment
		if (this != &src)
		{
			// shallow copying non-dynamic variables
			setQty(src.m_qty);
			setPrice(src.m_price);

			// deallocating previously allocated memory
			delete[] m_fruitName;

			// allocating new dynamic memory if needed
			if (src.m_fruitName != nullptr)
			{
				setName(src.m_fruitName);
			}
			else
			{
				m_fruitName = nullptr;
			}
		}

		return *this;
	}
	bool Basket::operator==(const Basket& rhs)
	{
		return strcmp(m_fruitName, rhs.m_fruitName) == 0 && m_price == rhs.m_price && m_qty == rhs.m_qty;
	}
	bool Basket::operator!=(const Basket& rhs)
	{
		return strcmp(m_fruitName, rhs.m_fruitName) != 0 || m_price != rhs.m_price || m_qty != rhs.m_qty;
	}
	std::ostream& operator<<(std::ostream& os, const Basket& bsk)
	{
		bsk.display(os);
		return os;
	}
}
