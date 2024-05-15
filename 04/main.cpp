#include "BV.h"
int main() {
	setlocale(0, "");
	BV a, b(10), c("111011101110"), d("111011101110", 10), e("111011101110", 16);
	cout << a << b << c << d << e;
	cout << c.Weight() << " " << e.Weight() << endl;
	if (c == e) cout << "Они равны" << endl;
	else cout << "Они не равны" << endl << "__" << endl;
	BV res1, res2, res3;
	cout << c;
	cout << d;
	res1 = d & c;
	cout << res1;
	res2 = d | c;
	cout << res2;
	res3 = d^c;
	cout << res3 << "__" << endl;
	cin >> b;
	cout << b;
	BV res;
	res = b << 4;
	cout << res;
	b >>= 4;
	cout << b;
	if (b != res) cout << "Они не равны" << endl;
	else cout << "Они равны" << endl;
	system("pause"); 
	return 0; 
}