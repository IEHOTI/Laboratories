#include "G:\Coding\Lib C\LibFun\Lib.h"
#include "G:\Coding\Lib C\LibFun\Sort.h"
int main() {
	setlocale(0, "");
	int x,n;
	Sort<int> A;
	cout << "������� ����� ���������:";
	cin >> n;
	int** arr = new int* [n];
	int** arr1 = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[1];
		arr1[i] = new int[1];
	}
	cout << "_______������ �� ���������� ����������_______" << endl;
	RMM(arr, n, 1);
	if (n <= 10) {
		OMM(arr, n, 1);
		cout << "___" << endl;
	}
	for (int i = 0; i < n; i++) arr1[i] = arr[i];
	cout << "                ��������� ��������� ������" << endl;
	x = A.Check(arr, n);
	cout << "����� ��������: " << x << endl << "                ���������� �����" << endl;
	x = A.Shell(arr, n);
	cout << "����� ��������: " << x << endl;
	x = A.Check(arr, n);
	cout << "����� ��������: " << x << endl;
	if (n <= 10) {
		OMM(arr, n, 1);
		cout << "___" << endl;
		OMM(arr1, n, 1);
		cout << "___" << endl;
	}
	cout << "                ��������� ������ ������" << endl;
	x = A.Check(arr1, n);
	cout << "����� ��������: " << x << endl << "                ������������� ����������" << endl;
	x = A.Heap(arr1, n);
	cout << "����� ��������: " << x << endl;
	x = A.Check(arr1, n);
	cout << "����� ��������: " << x << endl;
	if (n <= 10) {
		OMM(arr1, n, 1);
		cout << "___" << endl;
	}
	cout << "_______������������� ������ ��������� �������� �� �����������_______" << endl;
	RMMU(arr, n, 1);
	if (n <= 10) {
		OMM(arr, n, 1);
		cout << "___" << endl;
	}
	for (int i = 0; i < n; i++) arr1[i] = arr[i];
	cout << "                ��������� ��������� ������" << endl;
	x = A.Check(arr, n);
	cout << "����� ��������: " << x << endl << "                ���������� �����" << endl;
	x = A.Shell(arr, n);
	cout << "����� ��������: " << x << endl;
	x = A.Check(arr, n);
	cout << "����� ��������: " << x << endl;
	if (n <= 10) {
		OMM(arr, n, 1);
		cout << "___" << endl;
		OMM(arr1, n, 1);
		cout << "___" << endl;
	}
	cout << "                ��������� ������ ������" << endl;
	x = A.Check(arr1, n);
	cout << "����� ��������: " << x << endl << "                ������������� ����������" << endl;
	x = A.Heap(arr1, n);
	cout << "����� ��������: " << x << endl;
	x = A.Check(arr1, n);
	cout << "����� ��������: " << x << endl;
	if (n <= 10) {
		OMM(arr1, n, 1);
		cout << "___" << endl;
	}
	cout << "_______������������� ������ ��������� �������� �� ��������_______" << endl;
	RMMD(arr, n, 1);
	if (n <= 10) {
		OMM(arr, n, 1);
		cout << "___" << endl;
	}
	for (int i = 0; i < n; i++) arr1[i] = arr[i];
	cout << "                ��������� ��������� ������" << endl;
	x = A.Check(arr, n);
	cout << "����� ��������: " << x << endl << "                ���������� �����" << endl;
	x = A.Shell(arr, n);
	cout << "����� ��������: " << x << endl;
	x = A.Check(arr, n);
	cout << "����� ��������: " << x << endl;
	if (n <= 10) {
		OMM(arr, n, 1);
		cout << "___" << endl;
		OMM(arr1, n, 1);
		cout << "___" << endl;
	}
	cout << "                ��������� ������ ������" << endl;
	x = A.Check(arr1, n);
	cout << "����� ��������: " << x << endl << "                ������������� ����������" << endl;
	x = A.Heap(arr1, n);
	cout << "����� ��������: " << x << endl;
	x = A.Check(arr1, n);
	cout << "����� ��������: " << x << endl;
	if (n <= 10) {
		OMM(arr1, n, 1);
		cout << "___" << endl;
	}
	delete[] arr;
	delete[] arr1;
	system("pause");
	return 0;
}