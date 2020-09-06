//==============================================
// Name:           Seung Woo Ji
// Student Number: 116376195
// Email:          swji1@myseneca.ca
// Course:         OOP244 NGG
// Date:           January 14, 2020
//==============================================
// Workshop 1
//==============================================

#ifndef SDDS_TOOLS_H 
#define SDDS_TOOLS_H

#include "Word.h"

namespace sdds
{
	void toLowerCaseAndAlphabeticCopy(char des[], const char source[]);
	
	void title();
	
	void endList();
	
	void print(const Word* w, bool gotoNextLine);
	
	void report(const Word words[], int noOfWords, int longestWord);
	
	void swap(Word* p1, Word* p2);
	
	void sort(Word words[], int cnt);
}
#endif
