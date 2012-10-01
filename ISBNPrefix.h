#pragma once
#include "cstdlib"
#include "cstdio"
#include "iostream"
#include <cstring>
#include <iomanip>
using namespace std;


class ISBNPrefix
{
	//ISBNPrefix ip;
	FILE* fp;
public:
	//ISBNPrefix();
	ISBNPrefix(const char* filename);
	ISBNPrefix(const ISBNPrefix& source);
	bool isRegistered(int area) const;
	int minNoDigits(int area) const;
	bool isRegistered(int area, const char* publisher) const;
	~ISBNPrefix();
 	//ISBNPrefix& operator=(const ISBNPrefix& source);
	//these are new stuff added to A#3
};

