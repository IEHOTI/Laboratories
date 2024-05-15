#include "Array.h"
Array::Array(int x, int y)
{
	n = y;
	if (y > x) mem = y;
	else mem = x;
	a = new int[mem];
}
Array::Array(int* b, int m)
{
	n = mem = m;
	a = new int[mem];
	for (int i = 0; i < m; i++) {
		a[i] = b[i];
	}
}
Array::Array(const Array& x)
{
	n = x.n;
	mem = x.mem;
	a = new int[mem];
	for (int i = 0; i < n; i++) {
		a[i] = x.a[i];
	}
}
Array& Array::operator= (const Array& x)
{
	if (this != &x)
	{
		delete[] a;
		mem = x.mem;
		n = x.n;
		a = new int[mem];
		for (int i = 0; i < x.n; i++) {
			a[i] = x.a[i];
		}
	}
	return *this;
}
Array::~Array()
{
	delete[] a;
}
void Array::Scan()
{
	cin >> *this;
}
void Array::Print()
{
	cout << *this;
}
int& Array::operator[](int i)
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
int Array::FindKey(int key) {
	for (int i = 0; i < n; i++) {
		if (a[i] == key) {
			return i;
		}
	}
	return -1;
}
Array& Array::operator+=(int key)
{
	n++;
	if (n > mem) {
		mem = n;
		a = (int*)realloc(a, mem * sizeof(int));
	}
	a[n - 1] = key;
	return *this;
}
Array& Array::operator-=(int key)
{
	int i;
	do {
		i = this->FindKey(key);
		if (i != -1) {
			for (; i < n - 1; i++) {
				a[i] = a[i + 1];
			}
			n--;
		}
	} while (i != -1);
	return *this;
}
Array Array::operator+(int key)
{
	Array b;
	b = *this;
	b.n++;
	if (b.n > b.mem) {
		b.mem = b.n;
		b.a = (int*)realloc(b.a, b.mem * sizeof(int));
	}
	b.a[b.n - 1] = key;
	return b;
}
Array Array::operator-(int key)
{
	Array b(*this);
	int i;
	do {
		i = b.FindKey(key);
		if (i != -1) {
			for (; i < n - 1; i++) {
				b.a[i] = b.a[i + 1];
			}
			b.n--;
		}
	} while (i != -1);
	return b;
}
Array& Array::operator+=(Array b)
{
	int i = n;
	int j = 0;
	n = n + b.n;
	if (n > mem)
	{
		mem = n;
		a = (int*)realloc(a, mem * sizeof(int));
	}
	for (; i < n; i++, j++) {
		a[i] = b.a[j];
	}
	return *this;
}
Array Array::operator+(Array b)
{
	Array c(n + b.n);
	int k;
	if (n < b.n) k = b.n;
	else k = n;
	for (int i = 0; i < k; i++)
	{
		if (i < n) {
			c.a[i] = a[i];
		}
		if (i < b.n) {
			c.a[i + n] = b.a[i];
		}
	}
	return c;
}
Array& Array::AddPos(int pos, int key) {
	if (pos > n) { cout << "Позиция находится за границей массива. Возвращаю массив обратно." << endl; return *this; }
	n++;
	if (n > mem)
	{
		mem = n;
		a = (int*)realloc(a, mem * sizeof(int));
	}
	for (int i = n - 1; i > pos; i--) {
		a[i] = a[i - 1];
	}
	a[pos] = key;
	return *this;
}
Array& Array::DelPos(int pos)
{
	for (; pos < n - 1; pos++) a[pos] = a[pos + 1];
	return *this;
}
Array Array::DelPosNew(int pos)
{
	Array b(*this);
	b.DelPos(pos);
	return b;
}
bool Array::operator==(Array b)
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
bool Array::operator!=(Array b)
{
	if (*this == b) return false;
	return true;
}
int Array::Max()
{
	int max = a[0];
	int k = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] > max) { max = a[i]; k = i; }
	}
	return k;
}
int Array::Min()
{
	int min = a[0];
	int k = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < min) { min = a[i]; k = i; }
	}
	return k;
}
Array& Array::RandMas(int x, int y) {
	for (int i = 0; i < n; i++) a[i] = rand() % (y - x + 1) + x;
	return *this;
}
void Array::ShiftLeft(int pos) {
	for (; pos < n - 1; pos++)
	{
		a[pos] = a[pos + 1];
	}
	n--;
}
void Array::Sorting()
{
	for (int i = 1; i < n; i++) {
		int j = i - 1;
		while (j >= 0 && a[j] > a[j + 1]) {
			int t = a[j];
			a[j] = a[j + 1];
			a[j + 1] = t;
			j--;
		}
	}
}