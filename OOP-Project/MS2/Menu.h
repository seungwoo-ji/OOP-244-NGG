/* ------------------------------------------------------
Final Project Milestone 2
Module: Menu
Filename: Menu.h
Version 1.0
Author Seung Woo 
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
#ifndef _MENU_H
#define _MENU_H

#include <iostream>

namespace sdds
{
	const int MAX_NO_OF_ITEMS = 10;
	const int INDENTATION_SPACES = 4;

	class MenuItem
	{
		char* m_name;
		MenuItem();
		MenuItem(const char* name);
		MenuItem(const MenuItem& src) = delete;
		MenuItem& operator=(const MenuItem& src) = delete;
		~MenuItem();
		std::ostream& display(std::ostream& os = std::cout) const; // ostream as an optional argument
		friend class Menu; // set Menu as a friend of MenuItem
		friend std::ostream& operator<<(std::ostream& os, const MenuItem& src);
	};

	class Menu
	{
		char* m_title;
		MenuItem* m_items[MAX_NO_OF_ITEMS];
		int m_numItem;
		int m_idt;
		// additional functions
		void initItems();
		void emptyItem();

	public:
		Menu();
		Menu(const char* title, int idt = 0);
		Menu(const Menu& src);
		Menu& operator=(const Menu& src);
		~Menu();
		operator bool() const;
		bool isEmpty() const;
		std::ostream& display(std::ostream& os = std::cout) const;
		Menu& operator=(const char* title);
		void add(const char* itemName);
		Menu& operator<<(const char* itemName);
		int run() const;
		operator int() const;
	};
}
#endif // !_MENU_H

