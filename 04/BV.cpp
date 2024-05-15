#include "BV.h"
inline int BV::Input(const char* x, int A, int b) {  //строка, кол - во бит, кол - во букв в строке
	if (n % 8 == 0) m = n / 8;
	else m = (n / 8) + 1;
	a = new UC[m];
	int i = b-A;
	int j = 0;
	int k = 0;
	a[j] = 0;
	for (; k < m*8; i++) {
		a[j] <<= 1;
		if (i >= 0 && i < b) {
			if (x[i] == '1') {
				a[j] |= 1;
			}
		}
		k++;
		if ((k % 8 == 0) && (j + 1) < m) { 
			j++; 
			a[j] = 0;
		}
	}
	return m;
}
BV::BV() {
	n = 1;
	m = 1;
	a = new UC[m];
	a[0] = 0;
}
BV::BV(int N) {
	n = N;
	if (n % 8 == 0) m = n / 8;
	else m = (n / 8) + 1;
	a = new UC[m];
	for (int i = 0; i < m; i++) {
		a[i] = 0;
	}
}
BV::BV(const char* x) {
	n = strlen(x);
	m = Input(x, n, strlen(x));
}
BV::BV(const char* x, int N) {
	n = N;
	m = Input(x, n, strlen(x));
}
BV::BV(const BV& X) {
	n = X.n;
	m = X.m;
	a = new UC[m];
	for (int i = 0; i < m; i++) a[i] = X.a[i];
}
BV& BV::operator= (const BV& X) {
	if (this != &X) {
		delete[]a;
		n = X.n;
		m = X.m;
		a = new UC[m];
		for (int i = 0; i < m; i++) a[i] = X.a[i];
	}
	return *this;
}
int BV::Weight() {
	int k = 0;
	UC A = 1;
	A <<= 7;
	int i, j;
	for (i = 0, j = 0; j < m; i++) {
		if (a[j] & A) k++;
		A >>= 1;
		if ((i + 1) % 8 == 0) {
			A = 1;
			A <<= 7;
			j++;
		}
	}
	return k;
}
UC BV::operator[](int k) {
	if (k >= n) {
		cout << "Индекс выходит за пределы" << endl;
		return -1;
	}
	UC A = 1;
	int j = m-1-((k+(m*8)-n) / 8);
	A <<= (k - (8 - ((m * 8) - n))) %8;
	if (a[j] & A) return 1;
	return 0;
}
bool BV::operator==(BV& X) {
	if (m != X.m) return false;
	for (int i = 0; i < m; i++) {
		if (this->a[i] != X.a[i]) return false;
	}
	return true;
}
bool BV::operator!=(BV& X) {
	if (*this == X) return false;
	return true;
}
bool BV::operator<(BV& X) {
	if (m > X.m) return false;
	for (int i = 0; i < 8 * m; i++) {
		if (this->a[i] > X.a[i]) return false;
	}
	return true;
}
bool BV::operator>(BV& X) {
	if (m < X.m) return false;
	for (int i = 0; i < 8 * m; i++) {
		if (this->a[i] < X.a[i]) return false;
	}
	return true;
}
BV& BV::operator&=(BV& X) {
	int l = 0;
	if (m < X.m) {
		a = (UC*)realloc(a, X.m * sizeof(UC));
		for (; m < X.m; m++) a[m] = 0;
	}
	if (m > X.m) {
		X.a = (UC*)realloc(X.a, m * sizeof(UC));
		for (; X.m < m; X.m++) X.a[X.m] = 0;
	}
	if (n < X.n) { l = X.n - n; *this >>= l; }
	if (n > X.n) { l = n - X.n; X >>= l; }
	for (int i = 0; i < m; i++) {
		a[i] &= X.a[i];
	}
	*this <<= l;
	return *this;
}
BV BV::operator&(BV& X) {
	BV A(*this);
	A &= X;
	return A;
}
BV& BV::operator|=(BV& X) {
	int l;
	if (m < X.m) {
		a = (UC*)realloc(a, X.m * sizeof(UC));
		for (; m < X.m; m++) a[m] = 0;
	}
	if (m > X.m) {
		X.a = (UC*)realloc(X.a, m * sizeof(UC));
		for (; X.m < m; X.m++) X.a[X.m] = 0;
	}
	if (n < X.n) { l = X.n - n; *this >>= l; n = X.n; }
	if (n > X.n) { l = n - X.n; X >>= l; }
	for (int i = 0; i < m; i++) {
		a[i] |= X.a[i];
	}
	return *this;
}
BV BV::operator|(BV& X) {
	BV A(*this);
	A |= X;
	return A;
}
BV& BV::operator^=(BV& X) {
	int l;
	if (m < X.m) {
		a = (UC*)realloc(a, X.m * sizeof(UC));
		for (; m < X.m; m++) a[m] = 0;
	}
	if (m > X.m) {
		X.a = (UC*)realloc(X.a, m * sizeof(UC));
		for (; X.m < m; X.m++) X.a[X.m] = 0;
	}
	if (n < X.n) { l = X.n - n; *this >>= l; n = X.n; }
	if (n > X.n) { l = n - X.n; X >>= l;}
	for (int i = 0; i < m; i++) {
		a[i] ^= X.a[i];
		cout << X;
		cout << *this;
	}
	return *this;
}
BV BV::operator^(BV& X) {
	BV A(*this);
	A ^= X;
	return A;
}
BV& BV::operator~() {
	UC A = 255;
	for (int i = 0; i < m; i++) {
		a[i] ^= A;
	}
	return *this;
}
BV& BV::SetUp(int p, int k) {
	if (p+k > n) { cout << "Неверная позиция. Вектор не был изменён." << endl; return *this; }
	UC X = 1;
	int j = m - 1 - ((p + (m * 8) - n) / 8);
	X <<= (p - (8 - ((m * 8) - n))) % 8;
	for (int i = 0; i < k && j >= 0; i++) {
		this->a[j] ^= X;
		X <<= 1;
		if (X == 0) { j--; X = 1; }
	}
	return *this;
}
BV& BV::SetDown(int p, int k) {
	if (p+k > n) { cout << "Неверная позиция. Вектор не был изменён." << endl; return *this; }
	UC X = 1;
	int j = m - 1 - ((p + (m * 8) - n) / 8);
	X <<= (p - (8 - ((m * 8) - n))) % 8;
	for (int i = 0; i < k && j >= 0; i++) {
		this->a[j] ^= X;
		X <<= 1;
		if (X == 0) { j--; X = 1; }
	}
	return *this;
}
BV& BV::Invert(int p, int k) {
	if (p+k > n) { cout << "Неверная позиция. Вектор не был изменён." << endl; return *this; }
	UC X = 1;
	int j = m - 1 - ((p + (m * 8) - n) / 8);
	X <<= (p - (8 - ((m * 8) - n))) % 8;
	for (int i = 0; i < k && j >= 0; i++) {
		if (this->a[j] & X == 1) SetDown(p + i);
		else SetUp(p + i);
	}
	return *this;
}
BV& BV::operator<<=(int k) {
	UC A;
	int l, i;
	if (k >= n) {
		for (i = 0; i < m; i++) a[i] = 0;
		return *this;
	}
	if (abs(k / 8) > 1e-17) {
		l = k / 8;
		for (i = 0; i + l < m; i++) {
			a[i] = a[i + l];
			a[i + l] = 0;
			cout << *this << endl;
		}
		k %= 8;
	}
	if(abs(k / 8) < 1e-17) {
		if (m >= 2) {
			for (i = 0; i < m - 1; i++) {
				A = a[i + 1];
				a[i] <<= k;
				A >>= 8 - k;
				a[i] |= A;
			}
			a[m - 1] <<= k;
		}
		if (m < 2) { a[m - 1] <<= k; }
	}
	return *this;
}
BV BV::operator<<(int k) {
	BV A(*this);
	A <<= k;
	return A;
}
BV& BV::operator>>=(int k) {
	UC A;
	int i,j = m, l = 0;
	if (k >= n) {
		for (i = 0; i < m; i++) a[i] = 0;
	}
	if (k % 8 == 0) m += k / 8;
	else {
		m += (k / 8 + 1);
	}
	a = (UC*)realloc(a, m * sizeof(UC));
	for (; j < m; j++) a[j] = 0;
	if (abs(k / 8) > 1e-16) {
		l = k / 8;
		for (int i = m - 1; i > 0; i--) {
			a[i] = a[i-l];
			a[i-l] = 0;
		}
		k %= 8;
	}
	if (abs(k / 8) < 1e-17) {
		if (m >= 2) {
			for (i = m-1; i > 0; i--) {
				A = a[i-1];
				a[i] >>= k;
				A <<= 8 - k;
				a[i] |= A;
			}
			a[0] >>= k;
		}
		if (m < 2) a[m - 1] >> k;
	}
	if (n % 8 == 0) m = n / 8;
	else m = (n / 8) + 1;
	a = (UC*)realloc(a, m * sizeof(UC));
	return *this;
}
BV BV::operator>>(int k) {
	BV A(*this);
	A >>= k;
	return A;
}
