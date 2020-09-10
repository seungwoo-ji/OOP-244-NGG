/* ------------------------------------------------------
Final Project Milestone 6
Module: Parking
Filename: Parking.h
Version 1.0
Author Seung Woo
Student Number 116376195
Email swji1@myseneca.ca
Revision History
-----------------------------------------------------------
Date Reason
2020/3/9	Preliminary release
2020/3/25	Update for milestone #2
2020/4/10	Update for milestone #6
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef _SDDS_PARKING_H
#define _SDDS_PARKING_H

#include "Menu.h"
#include "Vehicle.h"
#include "Car.h"

namespace sdds
{
	const int MAX_NUM_PARKING_SPOTS = 100;

	class Parking
	{
		char* m_fname;
		Menu m_pmenu;
		Menu m_vmenu;
		int m_numSpots;
		Vehicle* m_pspots[MAX_NUM_PARKING_SPOTS];
		int m_numParkedVehicles;

		bool isEmpty() const;
		void parkingStatus() const;
		void parkVehicle();
		void returnVehicle();
		void listParkedVehicles() const;
		bool closeParking();
		bool exitParkingApp() const;
		bool loadDataFile();
		void saveDataFile();

		// additional private functions
		void initParkingSpots();
		void emptyParkingSpots();
		void setEmpty();
		int find() const;

	public:
		Parking(const char* datafile, int noOfSpots);
		~Parking();
		Parking(const Parking& src) = delete;
		Parking& operator=(const Parking& src) = delete;
		int run();
	};
}
#endif // !_SDDS_PARKING_H
