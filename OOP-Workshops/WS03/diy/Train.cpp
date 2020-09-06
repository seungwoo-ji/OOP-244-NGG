/***********************************************************************
// OOP244 Workshop 3: Classes & Privacy
// File Train.cpp
// Version 1.0
// Date	2020/02/01
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
	// store the train's name and ID after validation
	void Train::setTrain(const char* trainName, int trainID)
	{
		if (trainName == nullptr || strlen(trainName) == 0 || trainID < 1)
		{
			name[0] = '\0';
			id = 0;
			cargo = nullptr; // Uninitialized values in setTrain. cargo isn't set to nullptr in both branches	-0.25
		}
		else
		{
			strcpy(name, trainName);
			id = trainID;
			cargo = nullptr;	// assign nullptr to cargo to indicate there is no cargo in the train
		}
	}

	// load the cargo to the train 
	void Train::loadCargo(Cargo trainCargo)
	{
		cargo = new Cargo;

		*cargo = trainCargo;
	}

	// unload the cargo from the train
	void Train::unloadCargo()
	{
		delete cargo;
		cargo = nullptr;
	}

	// display the details of the train
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
				cout.setf(ios::fixed);
				cout.precision(2);
				cout << "Cargo: " << cargo->getDesc() << " Weight: " << cargo->getWeight() << endl;
			}
			else
			{
				cout << "No cargo on this train." << endl;
			}
		}

	}

	// check if the train is empty 
	bool Train::isEmpty() const
	{
		return name[0] == '\0' && id == 0;
	}

	// swap the cargo between two trains
	bool Train::swapCargo(Train& train)
	{
		Cargo* temp = nullptr;
		int valid = 0;

		if (cargo != nullptr && train.cargo != nullptr)
		{
			temp = cargo;
			cargo = train.cargo;
			train.cargo = temp;

			valid = 1;
		}
		return valid;
	}

	// increase the cargo of the train
	bool Train::increaseCargo(double numCargo)
	{
		int valid = 0;

		if (cargo->getWeight() < MAX_WEIGHT)
		{
			cargo->increaseWeight(numCargo);
			valid = 1;
		}
		return valid;
	}

	// decrease the cargo of the train
	bool Train::decreaseCargo(double numCargo)
	{
		int valid = 0;

		if (cargo != nullptr)
		{
			if (cargo->getWeight() > MIN_WEIGHT)
			{
				cargo->decreaseWeight(numCargo);
				valid = 1;
			}
		}
		return valid;
	}

	// store the description and weight of the cargo
	void Cargo::init(const char* cargoDesc, double cargoWeight)
	{
		bool valid = true;

		if (strlen(cargoDesc) > 20)
		{
			valid = false;
		}
		else
		{
			valid = cargoWeight >= MIN_WEIGHT && cargoWeight <= MAX_WEIGHT;
		}

		if (valid)
		{
			strcpy(description, cargoDesc);
			weight = cargoWeight;
		}
		else
		{
			strcpy(description, cargoDesc);
			weight = MIN_WEIGHT;
		}
	}

	// increase the cargo weight
	void Cargo::increaseWeight(double numCargo)
	{
		if ((weight + numCargo) >= MAX_WEIGHT)
		{
			weight = MAX_WEIGHT;
		}
		else
		{
			weight += numCargo;
		}
	}

	// decrease the cargo weight
	void Cargo::decreaseWeight(double numCargo)
	{
		if ((weight - numCargo) <= MIN_WEIGHT)
		{
			weight = MIN_WEIGHT;
		}
		else
		{
			weight -= numCargo;
		}
	}

	// return the cargo description
	const char* Cargo::getDesc() const
	{
		return description;
	}

	// return the cargo weight
	double Cargo::getWeight() const
	{
		return weight;
	}
}