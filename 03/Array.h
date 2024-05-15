#pragma once
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <locale>
using namespace std;
template < class X > class Array
{
	X* a;
	int n, mem;
	void ShiftLeft(int pos);
public:
	Array();
	Array(int m);
	Array(X* b, int m);
	Array(const Array<X>& x);
	Array<X>& operator= (const Array<X>& x);
	~Array();
	friend ostream& operator <<(ostream& f, Array<X>& Y) {
		Y.Print();
		return f;
	}
	friend istream& operator >>(istream& f, Array<X>& Y) {
		int x, z;
		cout << "Выберите тип ввода: вручную[0] или рандом[1]: ";
		do {
			f >> x;
			if (x == 0) {
				do {
					cout << "Введите кол-во элементов массива: ";
					f >> z;
					if (z <= 0) {
						cout << "Недопустимое кол-во элементов массива!" << endl;
					}
				} while (z <= 0);
				Y.mem = Y.n = z;
				Y.a = (X*)realloc(Y.a, Y.mem * sizeof(X));
				cout << "Вводите элементы массива:" << endl;
				for (int i = 0; i < z; i++) {
					cout << "Элемент [" << i << "]: ";
					f >> Y.a[i];
				}
			}
			else if (x == 1) {
				do {
					cout << "Введите кол-во элементов массива: ";
					f >> z;
					if (z <= 0) {
						cout << "Недопустимое кол-во элементов массива!" << endl;
					}
				} while (z <= 0);
				Y.mem = Y.n = z;
				Y.a = (X*)realloc(Y.a, Y.mem * sizeof(X));
				Y.RandMas(0, 255);
			}
			else { cout << "Вводите по-нормальному, пожалуйста... Ещё раз." << endl; }
		} while (x > 1 || x < 0);
		return f;
	}
	void Scan();
	void Print();
	X& operator[](int i);
	int FindKey(X key);
	Array<X>& operator+=(X key);
	Array<X>& operator-=(X key);
	Array<X> operator+(X key);
	Array<X> operator-(X key);
	Array<X>& operator+=(Array<X>);
	Array<X> operator+(Array<X>);
	Array<X>& DelPosEq(int pos); // удаление эл-та с позиции pos
	Array<X> DelPosNew(int pos); // формирование нового массива без элемента на позиции pos
	Array<X>& RandMas(int x, int y);
	bool operator==(Array<X>);
	bool operator!=(Array<X>);
	int Max();
	int Min();
	void Sorting();
};

template <class X> Array<X>::Array()
{
	n = mem = 1;
	a = new X[mem];
}
template <class X> Array<X>::Array(int m)
{
	n = mem = m;
	a = new X[mem];
}
template <class X> Array<X>::Array(X* b, int m)
{
	n = mem = m;
	a = new X[mem];
	for (int i = 0; i < m; i++) {
		a[i] = b[i];
	}
}
template <class X> Array<X>::Array(const Array<X>& x)
{
	n = x.n;
	mem = x.mem;
	a = new X[mem];
	for (int i = 0; i < n; i++) {
		a[i] = x.a[i];
	}
}
template <class X> Array<X>& Array<X>::operator= (const Array<X>& x)
{
	if (this != &x)
	{
		delete[] a;
		mem = x.mem;
		n = x.n;
		a = new X[mem];
		for (int i = 0; i < n; i++) {
			a[i] = x.a[i];
		}
	}
	return *this;
}
template <class X> Array<X>::~Array()
{
	delete[] a;
}
template <class X> void Array<X>::ShiftLeft(int pos) {
	for (; pos < n - 1; pos++)
	{
		a[pos] = a[pos + 1];
	}
	n--;
}
template <class X> void Array<X>::Scan()
{
	cin >> *this;
}
template <class X> void Array<X>::Print()
{
	int i;
	cout << "____Ваш массив____" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "Элемент [" << i << "]: " << a[i] << endl;
	}
}
template <class X> X& Array<X>::operator[](int i)
{
	if (i < 0 || i > n)
	{
		cout << "Индекс не входит в размер массива. Никаких действий совершено не было. Возвращаю значение первого элемента..." << endl;
		return a[0];
	}
	else {
		return a[i];
	}
}
template <class X> int Array<X>::FindKey(X key) {
	for (int i = 0; i < n; i++) {
		if (a[i] == key) {
			return i;
		}
	}
	return -1;
}
template <class X> Array<X>& Array<X>::operator+=(X key)
{
	n++;
	if (n > mem) {
		mem = n;
		a = (X*)realloc(a, mem * sizeof(X));
	}
	a[n - 1] = key;
	return *this;
}
template <class X> Array<X>& Array<X>::operator-=(X key)
{
	int i;
	do {
		i = this->FindKey(key);
		if (i != -1) {
			this->ShiftLeft(i);
		}
	} while (i != -1);
	return *this;
}
template <class X> Array<X> Array<X>::operator+(X key)
{
	Array<X> b(*this);
	b.n++;
	if (b.n > b.mem) {
		b.mem = b.n;
		b.a = (X*)realloc(b.a, b.mem * sizeof(X));
	}
	b.a[b.n - 1] = key;
	return b;
}
template <class X> Array<X> Array<X>::operator-(X key)
{
	Array b(*this);
	int i;
	do {
		i = b.FindKey(key);
		if (i != -1) {
			b.ShiftLeft(i);
		}
	} while (i != -1);
	return b;
}
template <class X> Array<X>& Array<X>::operator+=(Array<X> b)
{
	if (n + b.n > mem) {
		mem = n + b.n;
		a = (X*)realloc(a, mem * sizeof(X));
	}
	for (int i = n, j = 0; i < n + b.n; i++, j++)
	{
		a[i] = b.a[j];
	}
	n += b.n;
	return *this;
}
template <class X> Array<X> Array<X>::operator+(Array<X> b)
{
	Array<X> c(a, n + b.n);
	int i = n;
	for (int j = 0; j < b.n; i++,j++) {
		c.a[i] = b.a[j];
	}
	return c;
}
template <class X> Array<X>& Array<X>::DelPosEq(int pos)
{
	this->ShiftLeft(pos);
	return *this;
}
template <class X> Array<X> Array<X>::DelPosNew(int pos)
{
	Array b(*this);
	b.DelPosEq(pos);
	return b;
}
template <class X> bool Array<X>::operator==(Array<X> b)
{
	if (n != b.n) {
		return false;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (a[i] != b.a[i]) return false;
		}
	}
	return true;
}
template <class X> bool Array<X>::operator!=(Array<X> b)
{
	if (*this == b) return false;
	return true;
}
template <class X> int Array<X>::Max()
{
	X max = a[0];
	int k = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] > max) { max = a[i]; k = i; }
	}
	return k;
}
template <class X> int Array<X>::Min()
{
	X min = a[0];
	int k = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < min) { min = a[i]; k = i; }
	}
	return k;
}
template <class X> void Array<X>::Sorting()
{
	X t;
	for (int i = 1; i < n; i++) {
		int j = i - 1;
		while (j >= 0 && a[j] > a[j + 1]) {
			t = a[j];
			a[j] = a[j + 1];
			a[j + 1] = t;
			j--;
		}
	}
}
template <class X> Array<X>& Array<X>::RandMas(int x, int y)
{
	for (int i = 0; i < n; i++) a[i] = rand() % (y - x + 1) + x;
	return *this;
}	