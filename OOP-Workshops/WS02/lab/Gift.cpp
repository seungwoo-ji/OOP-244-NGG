//==============================================
// Name:           Seung Woo Ji
// Student Number: 116376195
// Email:          swji1@myseneca.ca
// Course:         OOP244 NGG
// Date:           January 22, 2020
//==============================================
// Workshop 2 In-Lab
// File Gift.cpp
//==============================================

#include <iostream>
#include "Gift.h"

using namespace std;

namespace sdds
{
	// store the gift's description
	void gifting(char* desc)
	{
		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1);
		cin >> desc;
	}

	// store the gift's price
	void gifting(double& price)
	{
		cout << "Enter gift price: ";
		cin >> price;

		while (price < 0 || price > MAX_PRICE)
		{
			cout << "Gift price must be between 0 and " << MAX_PRICE << endl;
			cout << "Enter gift price: ";
			cin >> price;
		}
	}

	// store the units of gift
	void gifting(int& unit)
	{
		cout << "Enter gift units: ";
		cin >> unit;

		while (unit < 1)
		{
			cout << "Gift units must be at least 1" << endl;
			cout << "Enter gift units: ";
			cin >> unit;
		}
	}

	// display the details of each gift
	void display(const Gift& gift)
	{
		cout << "Gift Details:" << endl;
		cout << "Description: " << gift.g_description << endl;
		cout << "Price: " << gift.g_price << endl;
		cout << "Units: " << gift.g_units << endl;
	}
}
