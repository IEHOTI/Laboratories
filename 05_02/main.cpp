#include "SBase.h"
int main() {
	setlocale(0, "");
	srand(time(0));
	SKbrd A;
	SQueue B(15);
	SFile C("G:\\Coding\\TestForCode\\A.txt");
	Freq F;
	Diap D;
	int n;
	cout << "�������� ������� �������� ������:" << endl;
	cout << "[1]� ����������" << endl;
	cout << "[2]� �����" << endl;
	cout << "[3]� ���������� �������" << endl;
	switch (cin >> n,n)
	{
	case 1: while (getchar() != '\n'); F.Calc(&A); cout << F << endl; D.Calc(&A); cout << D << endl; break;
	case 2: while (getchar() != '\n'); F.Calc(&C); cout << F << endl; D.Calc(&C); cout << D << endl; break;
	case 3: while (getchar() != '\n'); F.Calc(&B); cout << F << endl; D.Calc(&B); cout << D << endl; break;
	default:
		break;
	}
	system("pause");
	return 0;
}