#include "CStr.h"
char* CStr::generate(int x) { //97-a,122-z
	str = new char[x+1];
	for (int i = 0; i < x; i++) {
		str[i] = rand() % (122 - 98) + 97;
	}
	str[x] = '\0';
	return str;
}
CStr::CStr() {
	generate(rand() % (20 - 2) + 1);
}
CStr::CStr(char* A) {
	str = A;
}
CStr::CStr(int x) {
	if (x > 20) { cout << "Строка больше рекомендуемой длины. Сокращаю до 20..." << endl; x = 20; }
	generate(x);
}
CStr::CStr(const CStr& A) {
	str = A.str;
}
CStr::~CStr() {
	delete[] str;
}
CStr& CStr::operator=(const CStr& A) {
	if (this != &A)
	{
		delete[] str;
		int x = strlen(A.str);
		str = new char[x+1];
		strcpy_s(str, x + 1, A.str);
	}
	return *this;
}
CStr& CStr::operator=(const char* A) {
	strcpy_s(str, strlen(A) + 1, A);
	return *this;
}
int CStr::get_length() {
	return strlen(str);
}
bool CStr::operator>(CStr& A) {
	int x = this->get_length();
	if (x > A.get_length()) x = A.get_length();
	for (int i = 0; i < x; i++) {
		if (str[i] > A.str[i]) return true;
		else if (str[i] < A.str[i]) return false;
	}
	return false;
}
bool CStr::operator==(CStr& A) {
	int x = this->get_length();
	if (A.get_length() != x) { return false; }
	else {
		for (int i = 0; i < x; i++) {
			if (str[i] != A.str[i]) return false;
		}
	}
	return true;
}