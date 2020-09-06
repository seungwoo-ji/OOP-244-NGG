/***********************************************************************
// OOP244 Workshop 3: Classes & Privacy
// File Train.h
// Version 1.0
// Date	2020/02/01
// Author Seung Woo Ji
// Student Number 116376195
// Email swji1@myseneca.ca
// Description
// Includes safeguards, object declarations, and member function prototypes
// for train module.
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_TRAIN_H 
#define SDDS_TRAIN_H

namespace sdds
{
	const int MAX_NAME = 30;	// max legnth of a train's name excluding the null terminator
	const int MAX_DESC = 20;	// max length of a cargo's description excluding the null terminator
	const double MAX_WEIGHT = 700.555;	// max weight of a cargo
	const double MIN_WEIGHT = 40.444;	// min weight of a cargo

	class Cargo
	{
		char description[MAX_DESC + 1];
		double weight;

	public:
		void init(const char* cargoDesc, double cargoWeight);
		void increaseWeight(double numCargo);
		void decreaseWeight(double numCargo);
		const char* getDesc() const;
		double getWeight() const;
	};
	class Train
	{
		char name[MAX_NAME + 1];
		int id;
		Cargo* cargo;

	public:
		void setTrain(const char* trainName, int trainID);
		void loadCargo(Cargo trainCargo);
		void unloadCargo();
		void display() const;
		bool isEmpty() const;
		bool swapCargo(Train& train);
		bool increaseCargo(double numCargo);
		bool decreaseCargo(double numCargo);
	};
}
#endif