#pragma once
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <locale>
using namespace std;
class CStr
{
	char* str;
	char* generate(int);
public:
	CStr();
	CStr(char*);
	CStr(int);
	CStr(const CStr&);
	~CStr();
	CStr& operator=(const CStr&);
	CStr& operator=(const char*);
	bool operator>(CStr&);
	bool operator==(CStr&);
	int get_length();
	friend ostream& operator<<(ostream& stream, CStr& obj) {
		stream << obj.str << endl;
		return stream;
	}
};
