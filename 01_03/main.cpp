#include "rectangle.h"
int main() {
	setlocale(0, "");
	rectangle A, B, C;
	float x, y;
	A.Input();
	B.Input();
	if (A.CheckEq(B)) cout << "�������������� �����." << endl;
	else cout << "�������������� �� �����." << endl;
	if (A.CheckSim(B)) cout << "�������������� ��������." << endl;
	else cout << "�������������� �� ��������." << endl;
	if (A.CheckCross(B)) {
		cout << "�������������� ������������" << endl << endl;
		C = A.FindRec(B);
		C.Output();
		cout << "��������:" << C.FindP() << endl;
		cout << "�������:" << C.FindS() << endl;
		cout << "������ ��������� ����������:" << C.FindR() << endl;
		C.FindCR(x,y);
		cout << "����� ��������� ����������: [" << x << ";" << y << "]" << endl;
	}
	else cout << "�������������� �� ������������" << endl;
	system("pause");
	return 0;
}