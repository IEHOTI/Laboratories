#pragma once
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <locale>
using namespace std;
class Array
{
	int* a;
	int n, mem;
	void ShiftLeft(int);
public:
	Array(int x = 1, int y = 0);
	Array(int*, int);
	Array(const Array&);
	Array& operator= (const Array&);	
	~Array();
	friend ostream& operator <<(ostream& r, Array& Y) {
		r << "____��� ������____" << endl;
		for (int i = 0; i < Y.n; i++)
		{
			r << "������� [" << i << "]: " << Y.a[i] << endl;
		}
		return r;
	}
	friend istream& operator >>(istream& r, Array& Y) {
		int x, z;
		cout << "�������� ��� �����: �������[0] ��� ������[1]: ";
		do {
			r >> x;
			if (x == 0) {
				if (Y.n == 0) {
					do {
						cout << "������� ���-�� ��������� �������: ";
						r >> z;
						if (z <= 0) {
							cout << "������������ ���-�� ��������� �������!" << endl;
						}
					} while (z <= 0);
					Y.mem = Y.n = z;
					Y.a = (int*)realloc(Y.a, Y.mem * sizeof(int));
				}
				cout << "������� �������� �������:" << endl;
				for (int i = 0; i < Y.n; i++) {
					cout << "������� [" << i << "]: ";
					r >> Y.a[i];
				}
			}
			else if (x == 1) {
				if (Y.n == 0) {
					do {
						cout << "������� ���-�� ��������� �������: ";
						r >> z;
						if (z <= 0) {
							cout << "������������ ���-�� ��������� �������!" << endl;
						}
					} while (z <= 0);
					Y.mem = Y.n = z;
					Y.a = (int*)realloc(Y.a, Y.mem * sizeof(int));
				}
				Y.RandMas(0, 255);
			}
			else { cout << "������� ��-�����������, ����������... ��� ���." << endl; }
		} while (x > 1 || x < 0);
		return r;
	}
	void Scan();
	void Print();
	int& operator[](int);
	int FindKey(int);
	Array& operator+=(int);
	Array& operator-=(int);
	Array operator+(int);
	Array operator-(int);
	Array& operator+=(Array);
	Array operator+(Array);
	Array& RandMas(int, int);
	Array& AddPos(int, int);
	Array& DelPos(int);
	Array DelPosNew(int);
	bool operator==(Array);
	bool operator!=(Array);
	int Max();
	int Min();
	void Sorting();// ���������
};