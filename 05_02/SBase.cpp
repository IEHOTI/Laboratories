#include "SBase.h"
int SKbrd::Get() {
	int n = 0;
	int k;
	cout << "Введите элемент (Enter если закончили ввод) :";
	k = getchar();
	if (k == '\n' || k < '0'|| k >'9') return -1;
	else { do { n = n * 10 + (k - '0'); k = getchar(); } while (k != '\n'); }
	return n;
}
int SFile::Get() {
	int x;
	if (fscanf_s(f, "%d", &x) == EOF) { fseek(f, 0, SEEK_SET); return -1; }
	else return x;
}
SQueue::SQueue(int A) {
	a = new int[A];
	for (m = n = 0; n < A; n++) {
		a[n] = rand() % 50;
	}
}
int SQueue::Get() {
	if (m >= n) { m = 0; return -1; }
	else { m++; return a[m - 1]; }
}
void Freq::Calc(SBase* A) {
	int z = A->Get();
	while (z != -1) {
		counts[z]++;
		sum += z;
		z = A->Get();
	}
}
Diap::Diap() {
	min = max = -1;
	j = 0;
}
void Diap::Calc(SBase* A) {
	int z = A->Get();
	min = z;
	while (z != -1) {
		if (z < min) min = z;
		if (z > max) max = z;
		j++;
		z = A->Get();
	}
}