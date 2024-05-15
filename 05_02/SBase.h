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
	int* a, n, m;//n - общий, м - текущий(счетчик)
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
		stream << "||||||Класс Freq||||||" << endl;
		for (const auto& element : obj.counts)
			stream << "Элемент " << element.first << " Количество: " << element.second << endl;
		stream << "Сумма всех элементов: " << obj.sum << endl;
		return stream;
	}
};
class Diap : public Freq
{
	int min, max, j; // j = кол-во всех эл-тов.
public:
	Diap();
	void Calc(SBase*);
	friend ostream& operator<<(ostream& stream, Diap& obj) {
		stream << "||||||Класс Diap||||||" << endl;
		stream << "Минимальный элемент: " << obj.min << endl << "Максимальный элемент: " << obj.max << endl << "Всего чисел: " << obj.j << endl;
		return stream;
	}
};


