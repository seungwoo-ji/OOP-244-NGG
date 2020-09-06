/***********************************************************************
// OOP244 Workshop 3: Classes & Privacy
// File Train.cpp
// Version 1.0
// Date	2020/01/28
// Author Seung Woo Ji
// Student Number 116376195
// Email swji1@myseneca.ca
// Description
// Includes the definitions for the member functions of the objects.
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
#include "Train.h"

using namespace std;

namespace sdds
{
	void Train::setTrain(const char* trainName, int trainID)
	{
		if (trainName == nullptr || strlen(trainName) == 0 || trainID < 1)
		{
			name[0] = '\0';
			id = 0;
		}
		else
		{
			strcpy(name, trainName);
			id = trainID;
			cargo = nullptr;
		}
	}

	bool Train::isEmpty() const
	{
		return name[0] == '\0' && id == 0;
	}

	void Train::display() const
	{
		cout << "***Train Summary***" << endl;

		if (isEmpty())
		{
			cout << "This is an empty train." << endl;
		}
		else
		{
			cout << "Name: " << name << " ID: " << id << endl;

			if (cargo != nullptr)
			{
				cout << "Cargo: " << cargo->description << " Weight: " << cargo->weight << endl;
			}
			else
			{
				cout << "No cargo on this train." << endl;
			}
		}
	}

	void Train::loadCargo(Cargo trainCargo)
	{
		cargo = new Cargo;
		*cargo = trainCargo;
	}

	void Train::unloadCargo()
	{
		delete cargo;
		cargo = nullptr;
	}
}