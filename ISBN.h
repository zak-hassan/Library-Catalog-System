#pragma once
#include "cstdlib"
#include "cstdio"
#include "iostream"
#include <cstring>
#include <iomanip>
using namespace std;
#include "ISBNPrefix.h"


class ISBN
{

	char s_style[14];
	char p_area[6];
	char p_pub[8];
	char p_title[7];
	char check_digit;
	char s_string[11];
	bool reg;
	bool emp;

public:

	ISBN(void);
	ISBN(const char* str, const ISBNPrefix& list); 
	//ISBN(const ISBN& isbn); 
	bool isRegistered() const;
	bool isRegistered(const ISBNPrefix& list);
	bool empty() const;
	void toStr(char* str) const;
	void toStrWithStyle(char* str) const;
	bool read(istream& is, const ISBNPrefix& list);
	void display(ostream& os) const;
	~ISBN(void);
  friend bool operator==(const ISBN& left, const ISBN& right);
  friend ostream& operator<<(ostream& os, const ISBN& isbn);

};

extern int isValid(const char* str);

