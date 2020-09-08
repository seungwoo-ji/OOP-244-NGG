/* ------------------------------------------------------
Final Project Milestone 2
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
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef _SDDS_PARKING_H
#define _SDDS_PARKING_H

#include "Menu.h"

namespace sdds
{
	class Parking
	{
		char* m_fname;
		Menu m_pmenu;
		Menu m_vmenu;

		bool isEmpty() const;
		void parkingStatus() const;
		void parkVehicle() const;
		void returnVehicle() const;
		void listParkedVehicles() const;
		bool closeParking() const;
		bool exitParkingApp() const;
		bool loadDataFile() const;
		void saveDataFile() const;

	public:
		Parking();
		Parking(const char* fname);
		~Parking();
		Parking(const Parking& src) = delete;
		Parking& operator=(const Parking& src) = delete;
		int run();
	};
}
#endif // !_SDDS_PARKING_H
