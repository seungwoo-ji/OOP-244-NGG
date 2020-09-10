/* ------------------------------------------------------
Final Project Milestone 6
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
2020/4/10	Update for milestone #6
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <cstring>
#include "Parking.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Utils.h"

using namespace std;

namespace sdds
{
	Parking::Parking(const char* datafile, int noOfSpots)
	{
		if (datafile == nullptr || datafile[0] == '\0' || noOfSpots > MAX_NUM_PARKING_SPOTS || noOfSpots < 10)
		{
			m_fname = nullptr;
			m_numSpots = 0;
			initParkingSpots();
			setEmpty();
		}
		else
		{
			m_fname = new char[strlen(datafile) + 1];
			strcpy(m_fname, datafile);
			initParkingSpots();
			m_numSpots = noOfSpots;
			m_numParkedVehicles = 0;
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
			setEmpty();
		}
	}

	Parking::~Parking() 
	{
		saveDataFile();
		setEmpty();
	}

	bool Parking::isEmpty() const 
	{
		return m_fname == nullptr && m_numSpots == 0 && m_numParkedVehicles == 0 && m_pspots[0] == nullptr && m_pmenu.isEmpty() && m_vmenu.isEmpty();
	}

	void Parking::parkingStatus() const
	{
		cout << "****** Seneca Valet Parking ******" << endl;
		cout << "*****  Available spots: ";
		cout.width(4);
		cout.setf(ios::left);
		cout << m_numSpots - m_numParkedVehicles;
		cout.unsetf(ios::left);
		cout << " *****" << endl;
	}

	void Parking::parkVehicle()
	{
		int index;

		if (m_numParkedVehicles >= m_numSpots)
		{
			cout << "Parking is full" << endl;
		}
		else
		{
			switch (m_vmenu.run())
			{
			case 1:
			{
				Vehicle* car = new Car;
				car->read();

				index = find();

				m_pspots[index] = car;
				m_pspots[index]->setParkingSpot(index + 1);
				m_numParkedVehicles++;

				cout << endl;
				cout << "Parking Ticket" << endl;
				cout << *m_pspots[index];
				cout << endl;
			}
			break;
			case 2:
			{
				Vehicle* mc = new Motorcycle;
				mc->read();

				index = find();

				m_pspots[index] = mc;
				m_pspots[index]->setParkingSpot(index + 1);
				m_numParkedVehicles++;

				cout << endl;
				cout << "Parking Ticket" << endl;
				cout << *m_pspots[index];
				cout << endl;
			}
			break;
			case 3:
				cout << "Parking cancelled" << endl;
				break;
			}
		}
	}

	void Parking::returnVehicle()
	{
		char lplate[10];
		int index;
		bool isFound = false;

		cout << "Return Vehicle" << endl;
		cout << "Enter Licence Plate Number: ";

		do
		{
			cin.get(lplate, 10);
			cin.ignore(1000, '\n');

			if (strlen(lplate) < 1 || strlen(lplate) > MAX_LENGTH_PLATE)
			{
				cout << "Invalid Licence Plate, try again: ";
			}
		} while (strlen(lplate) < 1 || strlen(lplate) > MAX_LENGTH_PLATE);

		for (int i = 0; i < m_numSpots; ++i)
		{
			if (m_pspots[i] != nullptr && *m_pspots[i] == lplate)
			{
				index = i;
				isFound = true;
				i = m_numSpots;
			}
		}

		if (isFound)
		{
			cout << endl;
			cout << "Returning: " << endl;
			cout << *m_pspots[index];
			cout << endl;

			delete m_pspots[index];
			m_pspots[index] = nullptr;

			m_numParkedVehicles--;
		}
		else
		{
			cout << "License plate " << lplate << " Not found" << endl;
		}
	}

	void Parking::listParkedVehicles() const
	{
		cout << "*** List of parked vehicles ***" << endl;

		for (int i = 0; i < m_numSpots; ++i)
		{
			if (m_pspots[i] != nullptr)
			{
				cout << *m_pspots[i];
				cout << "-------------------------------" << endl;
			}
		}
	}

	bool Parking::closeParking()
	{
		bool result = true;

		if (m_numParkedVehicles == 0)
		{
			cout << "Closing Parking" << endl;
		}
		else
		{
			cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
			cout << "Are you sure? (Y)es/(N)o: ";

			result = confirm();

			if (result)
			{
				cout << "Closing Parking" << endl;

				for (int i = 0; i < m_numSpots; ++i)
				{
					if (m_pspots[i] != nullptr)
					{
						cout << endl;
						cout << "Towing request" << endl;
						cout << "*********************" << endl;
						cout << *m_pspots[i];
						delete m_pspots[i];
						m_pspots[i] = nullptr;
						m_numParkedVehicles--;
					}
				}
			}
			else
			{
				cout << "Aborted!" << endl;
			}
		}
		return result;
	}

	bool Parking::exitParkingApp() const
	{
		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";

		return confirm();
	}

	bool Parking::loadDataFile()
	{
		ifstream file;
		bool state = true;

		if (isEmpty()) 
		{
			state = false;
		}
		else
		{
			file.open(m_fname);

			while (file.good() && state && m_numParkedVehicles < m_numSpots)
			{
				Vehicle* v = nullptr;
				char type = '\0';

				file >> type;
				file.ignore();

				if (type == 'M')
				{
					v = new Motorcycle;
				}
				else
				{
					v = new Car;
				}

				v->setCsv(true);
				file >> *v;

				if (file.good())
				{
					v->setCsv(false);
					m_pspots[v->getParkingSpot() - 1] = v;
					m_numParkedVehicles++;
				}
				else if (file.eof())
				{
					delete v;
					state = true;
				}
				else
				{
					delete v;
					state = false;
				}
			}
		}
		file.close();
		return state;
	}

	void Parking::saveDataFile()
	{
		if (!isEmpty())
		{
			ofstream file;
			file.open(m_fname);

			if (file.is_open())
			{
				for (int i = 0; i < m_numSpots; ++i)
				{
					if (m_pspots[i] != nullptr)
					{
						m_pspots[i]->setCsv(true);

						file << *m_pspots[i];

						m_pspots[i]->setCsv(false);
					}
				}
			}
			file.close();
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

	// additional functions:

	// initialise the array of pointers to null pointers
	void Parking::initParkingSpots()
	{
		for (int i = 0; i < MAX_NUM_PARKING_SPOTS; ++i)
		{
			m_pspots[i] = nullptr;
		}
	}

	// deallocate the dynamic memory if needed -- possibly not needed...
	void Parking::emptyParkingSpots()
	{
		for (int i = 0; i < m_numSpots; ++i)
		{
			delete m_pspots[i];
			m_pspots[i] = nullptr;
		}
	}

	// set the object to the invalid empty state
	void Parking::setEmpty()
	{
		delete[] m_fname;
		m_fname = nullptr;

		//emptyParkingSpots();
		for (int i = 0; i < m_numSpots; ++i)
		{
			delete m_pspots[i];
			m_pspots[i] = nullptr;
		}

		m_numSpots = 0;
		m_numParkedVehicles = 0;
	}

	// find an index of the first available parking spot
	int Parking::find() const
	{
		int iSpot = -1; // index = -1 if not found

		for (int i = 0; i < m_numSpots; ++i)
		{
			if (m_pspots[i] == nullptr)
			{
				iSpot = i;
				i = m_numSpots; // breaks out of the loop
			}
		}

		return iSpot;
	}
}