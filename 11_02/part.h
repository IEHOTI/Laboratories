#pragma once
#include <iostream>
using namespace std;
class part
{
	int ID, task, time, mark, fail;
public:
	part();
	part(int);
	bool operator>(const part&);
	bool operator<(const part&);
	friend ostream& operator<<(ostream& stream, part& obj) {
		stream << " ID " << obj.ID << " ���������� ��������� ������: " << obj.mark << " ���������� �������� �������:" << obj.task << " ���������� ������������ �������: " << obj.time << " ���������� ������: " << obj.fail << endl;
		return stream;
	}
};
