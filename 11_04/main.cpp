#include "G:\Coding\Lib C\LibFun\Lib.h"
#include "func.h"

using namespace std;
int main() {
    //STN; 
    STL;
    int n,W; // ���������� ������ � ������������ ���
    cout << "������� ���������� ������:";
    cin >> n;
    vector<int> weights, values;
    RandArr(n, weights, values, W);
    vector<int> weights1(weights), weights2(weights);
    vector<int> values1(values), values2(values);
    cout << "����������� ���������� ���:" << W << endl;
    cout << "�������� ������� ���������" << endl;
    int res = Greedy(n,W,weights,values);
    cout << "���������:" << res << endl;
    if (n <= 30) {
        cout << "�������� ��������� ��������� �� ������ �����������." << endl;
        int res1 = Backtrack(weights1, values1, W);
        cout << "���������: " << res1 << endl;
    }
    cout << "�������� ��������� �� ������ ������������� ����������������." << endl;
    int res2 = Dynamic(n, W, weights2, values2);
    cout << "���������: " << res2 << endl;
    return 0;
}