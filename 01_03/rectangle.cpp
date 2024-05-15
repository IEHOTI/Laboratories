#include "rectangle.h"
rectangle::rectangle()
{
	*point = 0;
	*sides = 0;
}
rectangle::rectangle(float x, float y, float a, float b)
{
	point[0] = x;
	point[1] = y;
	sides[0] = a;
	sides[1] = b;
}
bool rectangle::CheckSquare()
{
	if (sides[0] == sides[1]) {
		return true;
	}
	return false;
}
bool rectangle::CheckEq(rectangle B)
{
	if (sides[0] == B.sides[0] && sides[1] == B.sides[1]) if ((point[0] - B.point[0] == 0) || (point[1] - B.point[1] == 0)) return true;
	else return false;
}
bool rectangle::CheckSim(rectangle B)
{
	if (sides[1] / B.sides[1] == sides[0] / B.sides[0]) return true;
	else return false;
}
bool rectangle::CheckCross(rectangle B)
{
	if (point[0] < B.point[0]) {
		if (this->sides[0] >= (B.point[0] - point[0]) && sides[1] >= (B.point[1] - point[1])) return true;
	}
	else if (abs(point[0] - B.point[0])<1e-6) {
		if (point[1] < B.point[1]) {
			if (sides[1] >= (B.point[1] - point[1])) return true;
		}
		else {
			if (B.sides[1] >= (point[1] - B.point[1])) return true;
		}
	}
	else {
		if (B.sides[0] >= (point[0] - B.point[0]) && B.sides[1] >= (point[1] - B.point[1])) return true;
	}
	return false;
}
void rectangle::Input()
{
	cout << "Введите координату \"x\" точки: ";
	cin >> point[0];
	cout << "Введите координату \"y\" точки: ";
	cin >> point[1];
	do {
		cout << "Введите длину прямоугольника: ";
		cin >> sides[0];
		cout << "Введите ширину прямоугольника: ";
		cin >> sides[1];
		if (sides[0] <= 0 || sides[1] <= 0) 
		{ 
			cout << "Стороны введены неправильно! Введите стороны заного:" << endl;
		}
	} while (sides[0] <= 0 || sides[1] <= 0);
	cout << "Прямоугольник создан" << endl;
	cout << "____________________________" << endl;
}
void rectangle::Output()
{
	cout << "Координаты точки:[" << point[0] << ";" << point[1] << "]" << endl;
	cout << "Длина прямоугольника: " << sides[0] << endl << "Ширина прямоугольника: " << sides[1] << endl;
	cout << "________________________" << endl;
}
void rectangle::Mult()
{
	float a;
	cout << "Введите число, на которое хотите умножить прямоугольник: ";
	cin >> a;
	sides[0] *= a;
	sides[1] *= a;
}
float rectangle::FindP()
{
	return (sides[0] + sides[1]) * 2;
}
float rectangle::FindS()
{
	return sides[0] * sides[1];
}
float rectangle::FindR()
{
	return sqrt(sides[0] * sides[0] + sides[1] * sides[1]) / 2;
}
void rectangle::FindCR(float& x0, float& y0)
{
	x0 = point[0] + (sides[0] / 2);
	y0 = point[1] + (sides[1] / 2);
}
rectangle rectangle::FindRec(rectangle B)
{
	rectangle C;
	if (point[0] < B.point[0])
	{
		C.point[0] = B.point[0];
		if (B.sides[0] + B.point[0] < sides[0] + point[0])
			C.sides[0] = B.sides[0];
		else
		C.sides[0] = sides[0] + point[0] - B.point[0];
		if (point[1] < B.point[1])
		{
			C.point[1] = B.point[1];
			if (B.sides[1] + B.point[1] < sides[1] + point[1])
				C.sides[1] = B.sides[1];
			else
			C.sides[1] = sides[1] + point[1] - B.point[1];
		}
		else {
			C.point[1] = point[1];
			if (B.sides[1] + B.point[1] > sides[1] + point[1])
				C.sides[1] = sides[1];
			else
			C.sides[1] = B.sides[1] + B.point[1] - point[1];
		}
	}
	else {
		C.point[0] = point[0];
		if (sides[0] + point[0] < B.sides[0] + B.point[0])
			C.sides[0] = sides[0];
		else
		C.sides[0] = B.sides[0] + B.point[0] - point[0];
		if (B.point[1] < point[1])
		{
			C.point[1] = B.point[1];
			if (sides[1] + point[1] < B.sides[1] + B.point[1])
				C.sides[1] = sides[1];
			else
				C.sides[1] = B.sides[1] + B.point[1] - point[1];
		}
		else {
			C.point[1] = B.point[1];
			if (sides[1] + point[1] > B.sides[1] + B.point[1])
				C.sides[1] = B.sides[1];
			else
				C.sides[1] = sides[1] + point[1] - B.point[1];
		}
	}
	return C;
}