/* ------------------------------------------------------
Final Project Milestone 2
Module: Parking
Filename: Parking.cpp
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
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <cctype>
#include "Parking.h"

using namespace std;

namespace sdds
{
	Parking::Parking()
	{
		m_fname = nullptr;
	}

	Parking::Parking(const char* fname)
	{
		if (fname == nullptr || fname[0] == '\0')
		{
			m_fname = nullptr;
		}
		else
		{
			m_fname = new char[strlen(fname) + 1];
			strcpy(m_fname, fname);


		}

		if (loadDataFile())
		{
			m_pmenu = Menu("Parking Menu, select an action:");
			m_pmenu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Close Parking (End of day)" << "Exit Program";

			m_vmenu = Menu("Select type of the vehicle:", 1);
			m_vmenu << "Car" << "Motorcycle" << "Cancel";
		}
		else
		{
			cout << "Error in data file" << endl;
			m_fname = nullptr;
		}



	}

	Parking::~Parking()
	{
		saveDataFile();

		delete[] m_fname;
		m_fname = nullptr;
	}

	bool Parking::isEmpty() const
	{
		return m_fname == nullptr;
	}

	void Parking::parkingStatus() const
	{
		cout << "****** Seneca Valet Parking ******" << endl;
	}

	void Parking::parkVehicle() const
	{
		switch (m_vmenu.run())
		{
		case 1:
			cout << "Parking Car" << endl;
			break;
		case 2:
			cout << "Parking Motorcycle" << endl;
			break;
		case 3:
			cout << "Cancelled parking" << endl;
			break;
		}
	}

	void Parking::returnVehicle() const
	{
		cout << "Returning Vehicle" << endl;
	}

	void Parking::listParkedVehicles() const
	{
		cout << "Listing Parked Vehicles" << endl;
	}

	bool Parking::closeParking() const
	{
		cout << "Closing Parking" << endl;

		return true;
	}

	bool Parking::exitParkingApp() const
	{
		char* select = new char[5];
		bool result;
		bool flag = true;

		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";

		do
		{

			//cin.get(select, 5);
			//// clear the buffer
			//cin.clear();
			//cin.ignore(1000, '\n');

			cin.getline(select, 5);
			cout << "cin fail?: " << cin.fail() << endl;
			
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
			}


			if (!strcmp(select, "y") || !strcmp(select, "Y"))
			{
				result = true;
				flag = false;
			}
			else if (!strcmp(select, "n") || !strcmp(select, "N"))
			{
				result = false;
				flag = false;
			}
			else
			{
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
			}
		} while (flag);

		delete[] select;

		return result;
	}

	bool Parking::loadDataFile() const
	{
		bool result = false;

		if (!isEmpty())
		{
			cout << "loading data from " << m_fname << endl;

			result = true;
		}

		return result;
	}

	void Parking::saveDataFile() const
	{
		if (!isEmpty())
		{
			cout << "Saving data into " << m_fname << endl;
		}
	}

	int Parking::run()
	{
		int result = 0;
		bool flag = true;

		if (isEmpty())
		{
			result = 1;
		}
		else
		{
			do
			{
				parkingStatus();

				switch (m_pmenu.run())
				{
				case 1:
					parkVehicle();
					break;
				case 2:
					returnVehicle();
					break;
				case 3:
					listParkedVehicles();
					break;
				case 4:
					if (closeParking())
					{
						flag = false;
					}
					break;
				case 5:
					if (exitParkingApp())
					{
						cout << "Exiting program!" << endl;
						flag = false;
					}
					break;
				}
			} while (flag);
		}

		return result;
	}
}