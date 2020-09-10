/* ------------------------------------------------------
Final Project Milestone 6
Module: Utils
Filename: Utils.cpp
Version 1.0
Author Seung Woo Ji
Student Number 116376195
Email swji1@myseneca.ca
Revision History
-----------------------------------------------------------
Date Reason
2020/4/10   Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <cstring>
#include "Utils.h"

using namespace std;

namespace sdds
{
	bool confirm(istream& istr)
	{
		char select[5];
		bool flag = true;
		bool option;

		do
		{
			istr.getline(select, 5);
			if (istr.fail())
			{
				istr.clear();
				istr.ignore(1000, '\n');
			}

			if (!strcmp(select, "y") || !strcmp(select, "Y"))
			{
				option = true;
				flag = false;
			}
			else if (!strcmp(select, "n") || !strcmp(select, "N"))
			{
				option = false;
				flag = false;
			}
			else
			{
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
			}
		} while (flag);

		return option;
	}
}