#include "part.h"
#include "G:\Coding\Lib C\LibFun\Lib.h"
#include "G:\Coding\Lib C\LibFun\Sort.h"
int main() {
	setlocale(0, "");
	STN;
	part** A;
	int n;
	cout << "������� ���������� ����������: ";
	cin >> n;
	A = new part*[n];
	for (int i = 0; i < n; i++) {
		A[i] = new part(i);
	}
	Sort<part>::Shell(A, n);
	ofstream F;
	F.open("G:\\Coding\\TestForCode\\A.txt");
	if (F.is_open()) {
		for (int i = n-1; i >= 0; i--) {
			F << n-i << " �����: " << *A[i];
		}
		cout << "���������� ������� �������� � ����." << endl;
		F.close();
	}
	else { cout << "�����-�� �������� � ������..." << endl; }
	for (int i = 0; i < n; i++) delete A[i];
	delete[] A;
	system("pause");
	return 0;
}
