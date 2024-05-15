#include "Array.h"
int main()
{
	setlocale(0, "");
	srand(time(NULL));
	cout << "___Тест типа int___" << endl;
	Array<int> A, B;
	int key = 3;
	cin >> A;
	cout << A;
	cout << "A[0]=" << A[0] << endl;
	cout << "Введите поиск ключа: ";
	cout << "Ваш ключ находится под номером:" << A.FindKey(key) << ". Если там \"-1\", значит ключ не находится в массиве." << endl;
	cout << "Максимальный элемент под номером:" << A.Max() << ", минимальный элемент под номером:" << A.Min() << endl;
	cout << "Отсортированный массив: " << endl;
	A.Sorting();
	A.Print();
	cout << "___Тестирование перегруженных операторов___" << endl;
	cout << "                +=                 " << endl;
	A += 7;
	A.Print();
	cout << "                +                 " << endl;
	B = A + 6;
	B.Print();
	cout << "                -=                 " << endl;
	A -= 7;
	A.Print();
	cout << "                -                 " << endl;
	B = A - 2;
	B.Print();
	cout << "                B+=A                 " << endl;
	B += A;
	B.Print();
	cout << "               A+B                 " << endl;
	Array<int> C = A + B;
	C.Print();
	cout << "                ==/!=                 " << endl;
	if (A == B) { cout << "Они равны." << endl; }
	else {
		cout << "Они не равны." << endl;
	}
	cout << endl << "___Тест типа float___" << endl;
	Array<float> A1, B1;
	float key1 = 3.3;
	cin >> A1;
	cout << A1;
	cout << "A[0]=" << A1[0] << endl;
	cout << "Введите поиск ключа: ";
	cout << "Ваш ключ находится под номером:" << A1.FindKey(key1) << ". Если там \"-1\", значит ключ не находится в массиве." << endl;
	cout << "Максимальный элемент под номером:" << A1.Max() << ", минимальный элемент под номером:" << A1.Min() << endl;
	cout << "Отсортированный массив: " << endl;
	A1.Sorting();
	A1.Print();
	cout << "___Тестирование перегруженных операторов___" << endl;
	cout << "                +=                 " << endl;
	A1 += 7.2;
	A1.Print();
	cout << "                +                 " << endl;
	B1 = A1 + 6.1;
	B1.Print();
	cout << "                -=                 " << endl;
	A1 -= 7.2;
	A1.Print();
	cout << "                -                 " << endl;
	B1 = A1 - 2.4;
	B1.Print();
	cout << "                B+=A                 " << endl;
	B1 += A1;
	B1.Print();
	cout << "               A+B                 " << endl;
	Array<float> C1 = A1 + B1;
	C1.Print();
	cout << "                ==/!=                 " << endl;
	if (A1 == B1) { cout << "Они равны." << endl; }
	else {
		cout << "Они не равны." << endl;
	}
	cout << endl << "___Тест типа char___" << endl;
	Array<char> A2, B2;
	char key2 = 20;
	cin >> A2;
	cout << A2;
	cout << "A[0]=" << A2[0] << endl;
	cout << "Введите поиск ключа: ";
	cout << "Ваш ключ находится под номером:" << A2.FindKey(key2) << ". Если там \"-1\", значит ключ не находится в массиве." << endl;
	cout << "Максимальный элемент под номером:" << A2.Max() << ", минимальный элемент под номером:" << A2.Min() << endl;
	cout << "Отсортированный массив: " << endl;
	A2.Sorting();
	A2.Print();
	cout << "___Тестирование перегруженных операторов___" << endl;
	cout << "                +=                 " << endl;
	A2 += 'b';
	A2.Print();
	cout << "                +                 " << endl;
	B2 = A2 + 'a';
	B2.Print();
	cout << "                -=                 " << endl;
	A2 -= 'b';
	A2.Print();
	cout << "                -                 " << endl;
	B2 = A2 - 'c';
	B2.Print();
	cout << "                B+=A                 " << endl;
	B2 += A2;
	B2.Print();
	cout << "               A+B                 " << endl;
	Array<char> C2 = A2 + B2;
	C2.Print();
	cout << "                ==/!=                 " << endl;
	if (A2 == B2) { cout << "Они равны." << endl; }
	else {
		cout << "Они не равны." << endl;
	}
	system("pause");
	return 0;
}