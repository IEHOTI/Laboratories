#include "Array.h"
int main()
{
	setlocale(0, "");
	cout << "_____������ ������_____" << endl;
	cout << "1" << endl;
	Array mas1;
	mas1.Scan(5);
	mas1.Print();
	cout << "2" << endl;
	Array mas2(mas1);
	cout << mas2;
	cout << "3" << endl;
	if (mas1 == mas2) { cout << "��� �����" << endl; }
	else { cout << "��� �� �����" << endl; }
	cout << "4" << endl;
	mas1 += 6;
	mas1.Print();
	if (mas1 == mas2) { cout << "��� �����" << endl; }
	else { cout << "��� �� �����" << endl; }
	cout << "5" << endl;
	Array mas3 = mas1 + 7;
	mas3.Print();
	cout << "6" << endl;
	mas3.DelPosEq(0);
	mas3.Print();
	cout << "7" << endl;
	Array mas4 = mas3.DelPosNew(6);
	mas4.Print();
	cout << "8" << endl;
	mas1 -= 1;
	if (mas1 == mas4) { cout << "��� �����" << endl; }
	else { cout << "��� �� �����" << endl; }
	cout << "9" << endl;
	int n, * b;
	cout << "������� ���-�� ��������� �������:";
	cin >> n;
	b = new int[n];
	cout << "������� �������� �������:" << endl;
	for (int i = 0; i < n; i++) {
		cout << "������� [" << i << "]: ";
		cin >> b[i];
	}
	Array mas5(b,n);
	cout << "10" << endl; 
	cout << "������������ � ��������: " << mas5.Max() << " ����������� � ��������: " << mas5.Min() << endl;
	cout << "11" << endl;
	mas5.Sorting();
	mas5.Print();
	cout << "12" << endl;
	Array mas6 = mas1 + mas5;
	cout << mas6;
	cout << "13" << endl;
	Array mas7;
	cin >> mas7;
	cout << "14" << endl; 
	if (mas7.FindKey(1)!= -1) { cout << "1 ������ � mas7" << endl; }
	else { cout << "1 �� ������ � mas7" << endl; }
	if (mas7.FindKey(10)!= -1) { cout << "10 ������ � mas7" << endl; }
	else { cout << "10 �� ������ � mas7" << endl; }
	Array mas8 = mas7 - 10;
	cout << "15" << endl;
	mas4 += mas7;
	mas4.Print();
	if (mas4 == mas6) { cout << "��� �����" << endl; }
	else { cout << "��� �� �����" << endl; }
	cout << "16" << endl;
	mas4 = mas6;
	cout << mas4;
	cout << "_____����� ������_____" << endl;
	system("pause");
	return 0;
}