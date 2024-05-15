#pragma once
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define _USE_MATH_DEFINES
class rectangle
{
	float point[2];
	float sides[2];
public:
	rectangle();
	rectangle(float x, float y, float a, float b);
	bool CheckSquare();
	bool CheckEq(rectangle B);
	bool CheckSim(rectangle B);
	bool CheckCross(rectangle B);
	void Input();
	void Output();
	void Mult();
	float FindP();
	float FindS();
	float FindR();
	void FindCR(float& x0, float& y0);
	rectangle FindRec(rectangle B);
};

