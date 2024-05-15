#include "CStrArray.h"
int main() {
	srand(time(0));
	setlocale(0, "");
	CStrArray A(5);
	cout << A << endl;
	A.sort_by_content();
	if (A.check_sort()) cout << "Ваш массив отсортирован по содержимому. ";
	else cout << "Ваш массив не отсортирован" << endl;
	cout << A << endl;
	cout << "||||Сортировка по длине строк||||" << endl;
	A.sort_by_length();
	cout << A << endl;
	char a[20];
	cout << "Введите строку поиска: " << endl;
	cin >> a;
	cout << endl;
	cout << "Номер строки: " << A.bin_search(a) << endl;
	system("pause");
	return 0;
}