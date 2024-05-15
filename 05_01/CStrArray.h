#pragma once
#include "CStr.h"
class CStrArray
{
	CStr* a;
	int x;
public:
	CStrArray(int);
	~CStrArray();
	CStr& operator[](int);
	void sort_by_content();
	void sort_by_length();
	int bin_search(const char*);
	bool check_sort();
	friend ostream& operator<<(ostream& stream, CStrArray& obj)
	{
		stream << "Ваш массив строк:" << endl;
		for (int i = 0; i < obj.x; i++) {
			stream << obj[i];
		}
		return stream;
	}
};


