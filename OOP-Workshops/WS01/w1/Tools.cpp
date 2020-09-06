//==============================================
// Name:           Seung Woo Ji
// Student Number: 116376195
// Email:          swji1@myseneca.ca
// Course:         OOP244 NGG
// Date:           January 14, 2020
//==============================================
// Workshop 1
//==============================================

#include <iostream>
#include <cctype>
#include <cstring>
#include "Tools.h"

using namespace std;

namespace sdds
{
	void toLowerCaseAndAlphabeticCopy(char des[], const char source[])
	{
		int i = 0, j = 0;
		char lower;
		for (; source[i] != 0; i++) 
		{
			lower = tolower(source[i]);
			if (lower >= 'a' && lower <= 'z') 
			{
				des[j++] = tolower(source[i]);
			}
		}
		des[j] = 0;
	}
	void title()
	{
		cout << "Text word stats: " << endl;
		cout << "Word: No of  occurrences." << endl << "------------------------------------------------" << endl;
	}
	void endList()
	{
		cout << "------------------------------------------------" << endl;
	}
	void print(const Word* w, bool gotoNextLine)
	{
		cout << w->letters << ": " << w->count;
		if (gotoNextLine) cout << endl;
	}
	void report(const Word words[], int noOfWords, int longestWord)
	{
		int i;
		int total;
		title();
		for (total = 0, i = 0; i < noOfWords; i++) 
		{
			print(&words[i], true);
			total += words[i].count;
		}
		endList();
		totalWordsStat(noOfWords, total, longestWord);
	}
	void swap(Word* p1, Word* p2)
	{
		Word w;
		w = *p1;
		*p1 = *p2;
		*p2 = w;
	}
	void sort(Word words[], int cnt)
	{
		int i, j;
		for (i = 0; i < cnt - 1; i++) 
		{
			for (j = 0; j < cnt - i - 1; j++) 
			{
				if (strcmp(words[j].letters, words[j + 1].letters) > 0) 
				{
					swap(&words[j], &words[j + 1]);
				}
			}
		}
	}
}