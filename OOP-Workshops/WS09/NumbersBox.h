/***********************************************************************
// OOP244 Workshop 9: Templates
// File: NumbersBox.h
// Version 1.0
// Date	2020/04/01
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
#ifndef _NUMBERSBOX_H
#define _NUMBERSBOX_H

#include <iostream>
#include <cstring>

namespace sdds
{
	const int MAX_CHARACTER_LENGTH = 15;
	const int MIN_SIZE_BOX = 1;

	template <class T>
	class NumbersBox
	{
		char m_name[MAX_CHARACTER_LENGTH + 1];
		int m_size;
		T* m_items;

	public:
		NumbersBox()
		{
			m_name[0] = '\0';
			m_size = 0;
			m_items = nullptr;
		}

		NumbersBox(int size, const char* name)
		{
			if (size < MIN_SIZE_BOX || name == nullptr || name[0] == '\0' || strlen(name) > MAX_CHARACTER_LENGTH)
			{
				*this = NumbersBox();
			}
			else
			{
				strcpy(m_name, name);
				m_size = size;
				m_items = new T[m_size];
			}
		}

		~NumbersBox()
		{
			delete[] m_items;
			m_items = nullptr;
		}

		T& operator[](int i)
		{
			return m_items[i];
		}

		NumbersBox<T>& operator*=(const NumbersBox<T>& other)
		{
			if (m_size == other.m_size)
			{
				for (int i = 0; i < m_size; ++i)
				{
					m_items[i] *= other.m_items[i];
				}
			}

			return *this;
		}

		NumbersBox<T>& operator+=(T num)
		{
			T* tempItems = new T[m_size + 1];

			for (int i = 0; i < m_size; ++i)
			{
				tempItems[i] = m_items[i];
			}

			tempItems[m_size++] = num;
					
			delete[] m_items;
			m_items = new T[m_size];

			for (int i = 0; i < m_size; ++i)
			{
				m_items[i] = tempItems[i];
			}

			delete[] tempItems;
			tempItems = nullptr;

			return *this;
		}

		std::ostream& display(std::ostream& os) const
		{
			if (m_name[0] == '\0' && m_size == 0 && m_items == nullptr)
			{
				os << "Empty Box" << std::endl;
			}
			else
			{
				os << "Box name: " << m_name << std::endl;
				for (int i = 0; i < m_size - 1; ++i)
				{
					os << m_items[i] << ", ";
				}

				os << m_items[m_size - 1] << std::endl;				
			}

			return os;
		}
		
	};

	template <class T>
	std::ostream& operator<<(std::ostream& os, NumbersBox<T>& box)
	{
		return box.display(os);
	}

}
#endif // !_NUMBERSBOX_H
