#include "CStrArray.h"
int main() {
	srand(time(0));
	setlocale(0, "");
	CStrArray A(5);
	cout << A << endl;
	A.sort_by_content();
	if (A.check_sort()) cout << "��� ������ ������������ �� �����������. ";
	else cout << "��� ������ �� ������������" << endl;
	cout << A << endl;
	cout << "||||���������� �� ����� �����||||" << endl;
	A.sort_by_length();
	cout << A << endl;
	char a[20];
	cout << "������� ������ ������: " << endl;
	cin >> a;
	cout << endl;
	cout << "����� ������: " << A.bin_search(a) << endl;
	system("pause");
	return 0;
}