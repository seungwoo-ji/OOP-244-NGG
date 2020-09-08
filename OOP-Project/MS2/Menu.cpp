/* ------------------------------------------------------
Final Project Milestone 2
Module: Menu
Filename: Menu.cpp
Version 1.0
Author Seung Woo Ji
Student Number 116376195
Email swji1@myseneca.ca
Revision History
-----------------------------------------------------------
Date Reason
2020/3/9	Preliminary release
2020/3/25	Update for milestone #2
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <cctype>
#include "Menu.h"

using namespace std;

namespace sdds
{
	// MenuItem class definitions:
	MenuItem::MenuItem()
	{
		m_name = nullptr;
	}

	MenuItem::MenuItem(const char* name)
	{
		if (name != nullptr && name[0] != '\0')
		{
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
		}
		else
		{
			m_name = nullptr;
		}
	}

	MenuItem::~MenuItem()
	{
		delete[] m_name;
		m_name = nullptr;
	}

	ostream& MenuItem::display(ostream& os) const
	{
		if (m_name != nullptr)
		{
			os << m_name << endl;
		}

		return os;
	}

	std::ostream& operator<<(std::ostream& os, const MenuItem& src)
	{
		return src.display(os);
	}

	// Menu class definitions:
	Menu::Menu()
	{
		m_title = nullptr;
		m_numItem = -1;
		initItems();
		m_idt = -1;
	}

	Menu::Menu(const char* title, int idt)
	{
		if (title != nullptr && title[0] != '\0')
		{
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);

			initItems();
			m_numItem = 0;
			m_idt = idt;
		}
		else
		{
			*this = Menu();
		}
	}

	Menu::Menu(const Menu& src)
	{
		m_title = nullptr;
		m_numItem = -1;

		*this = src;
	}

	Menu& Menu::operator=(const Menu& src)
	{
		if (this != &src)
		{
			m_idt = src.m_idt;

			delete[] m_title;

			if (src.m_title != nullptr)
			{
				m_title = new char[strlen(src.m_title) + 1];
				strcpy(m_title, src.m_title);
			}
			else
			{
				m_title = nullptr;
			}

			emptyItem();

			if (src.m_numItem >= 0)
			{
				m_numItem = 0;

				for (int i = 0; i < src.m_numItem; ++i)
				{
					add(src.m_items[i]->m_name);
				}
			}
			else
			{
				m_numItem = -1;
			}
		}

		return *this;
	}

	Menu::~Menu()
	{
		delete[] m_title;
		m_title = nullptr;

		emptyItem();
	}

	Menu::operator bool() const
	{
		return !isEmpty();
	}

	bool Menu::isEmpty() const
	{
		return m_title == nullptr && m_items[0] == nullptr && m_numItem == -1 && m_idt == -1;
	}

	ostream& Menu::display(ostream& os) const
	{
		if (isEmpty())
		{
			os << "Invalid Menu!" << endl;
		}
		else
		{
			int idtSize = INDENTATION_SPACES * m_idt + 1;
			char* idtSpace = new char[idtSize];

			for (int i = 0; i < idtSize - 1; ++i)
			{
				idtSpace[i] = ' ';
			}

			idtSpace[idtSize - 1] = '\0';

			os << idtSpace << m_title << endl;

			if (m_numItem <= 0)
			{
				os << "No Items to display!" << endl;
			}
			else
			{
				for (int i = 0; i < m_numItem; ++i)
				{
					os << idtSpace << i + 1 << "- " << *m_items[i];
				}

				os << idtSpace << "> ";
			}

			delete[] idtSpace;
		}

		return os;
	}

	Menu& Menu::operator=(const char* title)
	{
		if (title != nullptr && title[0] != '\0')
		{
			delete[] m_title;
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
		}
		else
		{
			*this = Menu();
		}

		return *this;
	}

	void Menu::add(const char* itemName)
	{
		bool valid = !isEmpty() && m_numItem < MAX_NO_OF_ITEMS;

		if (valid)
		{
			if (itemName != nullptr && itemName[0] != '\0')
			{
				m_items[m_numItem] = new MenuItem(itemName);
				m_numItem++;
			}
			else
			{
				*this = Menu();
			}
		}
	}

	Menu& Menu::operator<<(const char* itemName)
	{
		add(itemName);

		return *this;
	}

	int Menu::run() const
	{
		char select = 0;
		int numSelect = 0;
		bool flag = true;

		display();

		if (m_numItem > 0)
		{
			do
			{
				cin >> select;
				cin.clear();
				cin.ignore(1000, '\n');

				numSelect = select - '0';

				if (!isdigit(select))
				{
					cout << "Invalid Integer, try again: ";
				}
				else if (isdigit(select) && (numSelect > m_numItem || numSelect <= 0))
				{
					cout << "Invalid selection, try again: ";
				}
				else
				{
					flag = false;
				}

			} while (flag);
		}

		return numSelect;
	}

	Menu::operator int() const
	{
		return run();
	}

	// additional functions:

	// initialise the array of pointers to null pointers
	void Menu::initItems()
	{
		for (int i = 0; i < MAX_NO_OF_ITEMS; ++i)
		{
			m_items[i] = nullptr;
		}
	}

	// deallocate the dynamic memory if needed
	void Menu::emptyItem()
	{
		for (int i = 0; i < m_numItem; ++i)
		{
			delete m_items[i];
			m_items[i] = nullptr;
		}
	}
}
