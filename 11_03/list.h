#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class SList {
    vector<char*> list;
public:
    SList() {}
    bool check(const char*);
    void add(char*);
    void merge(SList&);
    int size() {
        return list.size();
    }
};

class HashTable {
    int q;
    vector<SList> table;
    int hash(const char*);
public:
    HashTable(int n) : table(n) { q = n; }
    void addUniqueString(char*);
    void mergeLists();
    int TotalComparisons();
    int getUniqueStringsCount() {
        return table[0].size();
    }
};