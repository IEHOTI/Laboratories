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
		stream << " ID " << obj.ID << " Количество набранных баллов: " << obj.mark << " Количество решённых заданий:" << obj.task << " Количество затраченного времени: " << obj.time << " Количество ошибок: " << obj.fail << endl;
		return stream;
	}
};
