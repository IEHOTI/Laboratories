#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <locale>
#include <map>
using namespace std;
class SBase
{
public:
	virtual int Get() = 0;
};
class SKbrd : public SBase
{
public:
	int Get();
};
class SFile : public SBase
{
	FILE* f;
public:
	SFile(const char* A){
		f = fopen(A, "r");
	}	
	~SFile() {
		_fcloseall();
	}
	int Get();
};
class SQueue : public SBase
{
	int* a, n, m;//n - �����, � - �������(�������)
public:
	SQueue(int);
	~SQueue() { delete[] a; };
	int Get();
};
class Freq
{
	map <int, int> counts;
	int sum = 0;
public:
	virtual void Calc(SBase*);
	friend ostream& operator<<(ostream& stream, Freq& obj) {
		stream << "||||||����� Freq||||||" << endl;
		for (const auto& element : obj.counts)
			stream << "������� " << element.first << " ����������: " << element.second << endl;
		stream << "����� ���� ���������: " << obj.sum << endl;
		return stream;
	}
};
class Diap : public Freq
{
	int min, max, j; // j = ���-�� ���� ��-���.
public:
	Diap();
	void Calc(SBase*);
	friend ostream& operator<<(ostream& stream, Diap& obj) {
		stream << "||||||����� Diap||||||" << endl;
		stream << "����������� �������: " << obj.min << endl << "������������ �������: " << obj.max << endl << "����� �����: " << obj.j << endl;
		return stream;
	}
};


