#include "G:\Coding\Lib C\LibFun\Lib.h"
#include "G:\Coding\Lib C\LibFun\Sort.h"
int main() {
	setlocale(0, "");
	int x,n;
	Sort<int> A;
	cout << "Введите число элементов:";
	cin >> n;
	int** arr = new int* [n];
	int** arr1 = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[1];
		arr1[i] = new int[1];
	}
	cout << "_______Массив со случайными значениями_______" << endl;
	RMM(arr, n, 1);
	if (n <= 10) {
		OMM(arr, n, 1);
		cout << "___" << endl;
	}
	for (int i = 0; i < n; i++) arr1[i] = arr[i];
	cout << "                Проверяем начальный массив" << endl;
	x = A.Check(arr, n);
	cout << "Число проверок: " << x << endl << "                Сортировка Шелла" << endl;
	x = A.Shell(arr, n);
	cout << "Число проверок: " << x << endl;
	x = A.Check(arr, n);
	cout << "Число проверок: " << x << endl;
	if (n <= 10) {
		OMM(arr, n, 1);
		cout << "___" << endl;
		OMM(arr1, n, 1);
		cout << "___" << endl;
	}
	cout << "                Проверяем массив заново" << endl;
	x = A.Check(arr1, n);
	cout << "Число проверок: " << x << endl << "                Пирамидальная сортировка" << endl;
	x = A.Heap(arr1, n);
	cout << "Число проверок: " << x << endl;
	x = A.Check(arr1, n);
	cout << "Число проверок: " << x << endl;
	if (n <= 10) {
		OMM(arr1, n, 1);
		cout << "___" << endl;
	}
	cout << "_______Упорядоченный массив случайных значений по возрастанию_______" << endl;
	RMMU(arr, n, 1);
	if (n <= 10) {
		OMM(arr, n, 1);
		cout << "___" << endl;
	}
	for (int i = 0; i < n; i++) arr1[i] = arr[i];
	cout << "                Проверяем начальный массив" << endl;
	x = A.Check(arr, n);
	cout << "Число проверок: " << x << endl << "                Сортировка Шелла" << endl;
	x = A.Shell(arr, n);
	cout << "Число проверок: " << x << endl;
	x = A.Check(arr, n);
	cout << "Число проверок: " << x << endl;
	if (n <= 10) {
		OMM(arr, n, 1);
		cout << "___" << endl;
		OMM(arr1, n, 1);
		cout << "___" << endl;
	}
	cout << "                Проверяем массив заново" << endl;
	x = A.Check(arr1, n);
	cout << "Число проверок: " << x << endl << "                Пирамидальная сортировка" << endl;
	x = A.Heap(arr1, n);
	cout << "Число проверок: " << x << endl;
	x = A.Check(arr1, n);
	cout << "Число проверок: " << x << endl;
	if (n <= 10) {
		OMM(arr1, n, 1);
		cout << "___" << endl;
	}
	cout << "_______Упорядоченный массив случайных значений по убыванию_______" << endl;
	RMMD(arr, n, 1);
	if (n <= 10) {
		OMM(arr, n, 1);
		cout << "___" << endl;
	}
	for (int i = 0; i < n; i++) arr1[i] = arr[i];
	cout << "                Проверяем начальный массив" << endl;
	x = A.Check(arr, n);
	cout << "Число проверок: " << x << endl << "                Сортировка Шелла" << endl;
	x = A.Shell(arr, n);
	cout << "Число проверок: " << x << endl;
	x = A.Check(arr, n);
	cout << "Число проверок: " << x << endl;
	if (n <= 10) {
		OMM(arr, n, 1);
		cout << "___" << endl;
		OMM(arr1, n, 1);
		cout << "___" << endl;
	}
	cout << "                Проверяем массив заново" << endl;
	x = A.Check(arr1, n);
	cout << "Число проверок: " << x << endl << "                Пирамидальная сортировка" << endl;
	x = A.Heap(arr1, n);
	cout << "Число проверок: " << x << endl;
	x = A.Check(arr1, n);
	cout << "Число проверок: " << x << endl;
	if (n <= 10) {
		OMM(arr1, n, 1);
		cout << "___" << endl;
	}
	delete[] arr;
	delete[] arr1;
	system("pause");
	return 0;
}