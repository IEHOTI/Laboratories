#pragma once
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <locale>
using namespace std;
typedef unsigned char UC;
class BV
{
	UC* a;
	int n, m;
	int Input(const char*, int, int); // строка, кол-во бит, кол-во букв в строке, позиция встраивания(0-m)
	void Output(int, int);
public:
	BV();
	BV(int);
	BV(const char*);
	BV(const char*, int);
	BV(const BV&);
	BV& operator=(const BV&);
	~BV() { delete[] a; };
	friend ostream& operator<<(ostream& r, BV& X) {
		UC A = 1;
		A <<= 7;
		int i, j;
		for (i = 0, j = 0;i < X.n && j < X.m;) {
			if (X.a[j] & A) r << "1";
			else r << "0";
			A >>= 1;
			i++;
			if (i % 4 == 0) { r << " "; }
			if (i % 8 == 0) {
				A = 1;
				A <<= 7;
				j++;
			}
		}
		r << endl;
		return r;
	}
	friend istream& operator>>(istream& r, BV& X) {
		char o[80];
		cout << "Вводите вектор: ";
		gets_s(o, 80);
		X.n = strlen(o);
		o[X.n] = '\0';
		delete[] X.a;
		X.Input(o, X.n, X.n);
	}
	int Weight();
	UC operator[](int);
	bool operator==(BV&);
	bool operator!=(BV&);
	bool operator<(BV&);
	bool operator>(BV&);
	BV operator&(BV&);
	BV& operator &=(BV&);
	BV operator|(BV&);
	BV& operator|=(BV&);
	BV operator^(BV&);
	BV& operator^=(BV&); // фикс операторы под >>=
	BV& operator ~();
	BV operator<<(int);
	BV& operator<<=(int);
	BV operator>>(int);
	BV& operator>>=(int);
	BV& SetUp(int p, int k = 1);
	BV& SetDown(int p, int k = 1);
	BV& Invert(int p, int k = 1);
};

