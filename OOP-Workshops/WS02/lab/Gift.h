//==============================================
// Name:           Seung Woo Ji
// Student Number: 116376195
// Email:          swji1@myseneca.ca
// Course:         OOP244 NGG
// Date:           January 22, 2020
//==============================================
// Workshop 2 In-Lab
// File Gift.h
//==============================================

#ifndef SDDS_GIFT_H 
#define SDDS_GIFT_H

namespace sdds
{
	const int MAX_DESC = 15;				// max length of Gift's description
	const double MAX_PRICE = 999.99;		// max price of Gift

	// Gift structure declaration 
	struct Gift								
	{
		char g_description[MAX_DESC + 1];
		double g_price;
		int g_units;
	};

	// Function Prototypes
	void gifting(char* desc);

	void gifting(double& price);

	void gifting(int& unit);

	void display(const Gift& gift);
}
#endif