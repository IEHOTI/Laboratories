#include "part.h"
part::part() {
	ID = task = mark = time = fail = -1;
}
part::part(int i) {
	ID = i;
	task = rand() % (5 - 0 + 1) + 0;
	mark = rand() % (25 - 0 + 1) + 0;
	time = rand() % (300 - 60 + 1) + 60;
	fail = rand() % (20 - 0 + 1) + 0;
}
bool part::operator<(const part& A) {
	if (this->mark < A.mark) return true;
	else if (this->mark > A.mark) return false;
	else {
		if (this->task < A.task) return true;
		else if (this->task > A.task) return false;
		else {
			if (this->time > A.time) return true;
			else if (this->time < A.time) return false;
			else {
				if (this->fail > A.fail) return true;
				else if (this->fail < A.fail) return false;
				else {
					if (this->ID < A.ID) return true;
					else return false;
				}
			}
		}
	}
}
bool part::operator>(const part& A) {
	if (*this < A) return false;
	return true;
}