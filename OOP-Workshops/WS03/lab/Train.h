/***********************************************************************
// OOP244 Workshop 3: Classes & Privacy
// File Train.h
// Version 1.0
// Date	2020/01/28
// Author Seung Woo Ji
// Student Number 116376195
// Email swji1@myseneca.ca
// Description
// Includes safeguards, object declarations, and their member function protoptypes.
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
	const int MAX_NAME = 30;	// max legnth of Train's name excluding the null terminator
	const int MAX_DESC = 20;	// max length of Cargo's description excluding the null terminator

	struct Cargo
	{
		char description[MAX_DESC + 1];
		double weight;
	};
	class Train
	{
		char name[MAX_NAME + 1];
		int id;
		Cargo* cargo;

	public:
		void setTrain(const char* trainName, int trainID);
		bool isEmpty() const;
		void display() const;
		void loadCargo(Cargo trainCargo);
		void unloadCargo();
	};
}
#endif