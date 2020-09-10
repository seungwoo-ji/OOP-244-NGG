/* ------------------------------------------------------
Final Project Milestone 5
Module: Vehicle
Filename: Vehicle.h
Version 1.0
Author Seung Woo Ji
Student Number 116376195
Email swji1@myseneca.ca
Revision History
-----------------------------------------------------------
Date Reason
2020/3/9	Preliminary release
2020/3/29   Update for milestone #4
2020/4/01   Update for milestone #5
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef _SDDS_VEHICLE_H
#define _SDDS_VEHICLE_H

#include "ReadWritable.h"

namespace sdds
{
	const int MAX_LENGTH_PLATE = 8;
	const int MAX_LENGTH_MODEL = 60;
	const int MIN_LENGTH_MODEL = 2;

	class Vehicle : public ReadWritable
	{
		char m_lplate[MAX_LENGTH_PLATE + 1];
		char* m_mkmodel;
		int m_psnum;

	public:
		Vehicle();
		Vehicle(const char* lplate, const char* mkmodel);
		Vehicle(const Vehicle& src) = delete;
		Vehicle& operator=(const Vehicle& src) = delete;
		virtual ~Vehicle();

	protected:
		void setEmpty();
		bool isEmpty() const;
		const char* getLicensePlate() const;
		const char* getMakeModel() const;
		void setMakeModel(const char* mkmodel);
		void setLicensePlate(const char* lplate);

	public:
		int getParkingSpot() const;
		void setParkingSpot(int psnum = 0);
		bool operator==(const char* lplate) const;
		bool operator==(const Vehicle& rhs) const;
		virtual std::istream& read(std::istream& istr = std::cin);
		virtual std::ostream& write(std::ostream& ostr = std::cout) const;
	};
}
#endif // !_SDDS_VEHICLE_H
