#include "rectangle.h"
int main() {
	setlocale(0, "");
	rectangle A, B, C;
	float x, y;
	A.Input();
	B.Input();
	if (A.CheckEq(B)) cout << "Прямоугольники равны." << endl;
	else cout << "Прямоугольники не равны." << endl;
	if (A.CheckSim(B)) cout << "Прямоугольники подобные." << endl;
	else cout << "Прямоугольники не подобные." << endl;
	if (A.CheckCross(B)) {
		cout << "Прямоугольники пересекаются" << endl << endl;
		C = A.FindRec(B);
		C.Output();
		cout << "Периметр:" << C.FindP() << endl;
		cout << "Площадь:" << C.FindS() << endl;
		cout << "Радиус описанной окружности:" << C.FindR() << endl;
		C.FindCR(x,y);
		cout << "Центр описанной окружности: [" << x << ";" << y << "]" << endl;
	}
	else cout << "Прямоугольники не пересекаются" << endl;
	system("pause");
	return 0;
}