#include "G:\Coding\Lib C\LibFun\Lib.h"
#include "func.h"

using namespace std;
int main() {
    //STN; 
    STL;
    int n,W; // Количество грузов и максимальный вес
    cout << "Введите количество грузов:";
    cin >> n;
    vector<int> weights, values;
    RandArr(n, weights, values, W);
    vector<int> weights1(weights), weights2(weights);
    vector<int> values1(values), values2(values);
    cout << "Максимально допустимый вес:" << W << endl;
    cout << "Проверка жадного алгоритма" << endl;
    int res = Greedy(n,W,weights,values);
    cout << "Результат:" << res << endl;
    if (n <= 30) {
        cout << "Проверка переборки вариантов на основе бэктрекинга." << endl;
        int res1 = Backtrack(weights1, values1, W);
        cout << "Результат: " << res1 << endl;
    }
    cout << "Проверка алгоритма на основе динамического программирования." << endl;
    int res2 = Dynamic(n, W, weights2, values2);
    cout << "Результат: " << res2 << endl;
    return 0;
}