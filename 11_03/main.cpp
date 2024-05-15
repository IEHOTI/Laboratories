#include "list.h"
#include "G:\Coding\Lib C\LibFun\Lib.h"
using namespace std;
int main() {
    //STN;
    STL;
    int n = 200; 
    int range = 26; // диапазон символов строк (a-z)
    int q = 1000; // размер хеш-таблицы
    char** strings = new char* [n];
    for (int i = 0; i < n; i++) {
        int l = rand() % 10 + 1;
        strings[i] = new char[l + 1];
        for (int j = 0; j < l; j++) {
            strings[i][j] = 'a' + rand() % range;
        }
        strings[i][l] = '\0';
    }
   /* for (int i = n - 2; i < n; i++) {
        strings[i] = new char[6];
        for (int j = 0; j < 5; j++) strings[i][j] = 'a';
        strings[i][5] = '\0';
    }*/
    HashTable ht(q);
    for (int i = 0; i < n; i++) {
        ht.addUniqueString(strings[i]);
    }
    ht.mergeLists();
    cout << "Всего сравнений: " << ht.TotalComparisons() << endl;
    cout << "Число уникальных строк: " << ht.getUniqueStringsCount() << endl;

    for (int i = 0; i < n; i++) {
        delete[] strings[i];
    }
    delete[] strings;

    return 0;
}