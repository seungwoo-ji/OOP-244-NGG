//==============================================
// Name:           Seung Woo Ji
// Student Number: 116376195
// Email:          swji1@myseneca.ca
// Course:         OOP244 NGG
// Date:           January 22, 2020
//==============================================
// Workshop 2 DYI
// File Gift.cpp
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
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
		cin.ignore(2000, '\n'); // clear the input buffer
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


	// store gift's description, price, and unit then attempt to wrap the gift
	void gifting(Gift& gift)
	{
		cout << "Preparing a gift..." << endl;
		gifting(gift.g_description);
		gifting(gift.g_price);
		gifting(gift.g_units);
		wrap(gift);
	}

	// display the details of the gift
	void display(const Gift& gift)
	{
		cout << "Gift Details:" << endl;
		cout << "Description: " << gift.g_description << endl;
		cout << "Price: " << gift.g_price << endl;
		cout << "Units: " << gift.g_units << endl;

		if (gift.wrap == nullptr)
		{
			cout << "Unwrapped" << endl;
		}
		else
		{
			cout << "Wrap Layers: " << gift.wrap_layers << endl;

			for (int i = 0; i < gift.wrap_layers; i++)
			{
				cout << "Wrap #" << i + 1 << ": " << gift.wrap[i].pattern << endl;
			}
		}
	}

	// determine if the wrapping was successful, store the number of
	// wrapping layers, and patterns
	bool wrap(Gift& gift)
	{
		int valid = 1;

		if (gift.wrap_layers)
		{
			cout << "Gift is already wrapped!" << endl;
			valid = 0;
		}
		else
		{
			cout << "Wrapping gifts..." << endl;
			cout << "Enter the number of wrapping layers for the Gift: ";
			cin >> gift.wrap_layers;

			while (gift.wrap_layers < 1)
			{
				cout << "Layers at minimum must be 1, try again." << endl;
				cout << "Enter the number of wrapping layers for the Gift: ";
				cin >> gift.wrap_layers;
			}

			gift.wrap = new Wrapping[gift.wrap_layers];

			for (int i = 0; i < gift.wrap_layers; i++)
			{
				char temp[MAX_PATTERN + 1] = { 0 };

				cin.width(MAX_PATTERN + 1); // set the width to take only 20 + 1 characters from user input 

				cout << "Enter wrapping pattern #" << i + 1 << ": ";
				cin >> temp;
				cin.ignore(2000, '\n'); // clear the input buffer

				gift.wrap[i].pattern = new char[strlen(temp) + 1];

				strcpy(gift.wrap[i].pattern, temp);
			}
		}
		return valid;
	}

	bool unwrap(Gift& gift)
	{
		int valid = 1;

		if (!gift.wrap_layers)
		{
			cout << "Gift isn't wrapped! Can't unwrap." << endl;
			valid = 0;
		}
		else
		{
			cout << "Gift being unwrapped." << endl;

			for (int i = 0; i < gift.wrap_layers; i++)
			{
				delete[] gift.wrap[i].pattern;
			}

			gift.wrap_layers = 0;

			delete[] gift.wrap;

			gift.wrap = nullptr;
		}
		return valid;
	}
}