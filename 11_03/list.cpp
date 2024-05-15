#include "list.h"
bool SList::check(const char* str) {
    for (char* s : list) {
        if (strcmp(s, str) == 0) {
            return true;
        }
    }
    return false;
}
void SList::add(char* s) {
    if (!check(s)) {
        list.push_back(s);
    }
}
void SList::merge(SList& A) {
    for (char* s : A.list) {
        add(s);
    }
}
int HashTable::hash(const char* s) {
    int H = 0;
    int l = strlen(s);
    for (int i = 0; i < l; i++) {
        H = ((H + s[i]) % q * 31) % q;
    }
    return H;
}
void HashTable::addUniqueString(char* s) {
    int index = hash(s);
    table[index].add(s);
}
void HashTable::mergeLists() {
    SList mergeList;
    for (SList& list : table) {
        mergeList.merge(list);
    }
    table.clear();
    table.push_back(mergeList);
}
int HashTable::TotalComparisons() {
    int total = 0;
    for (SList& list : table) {
        total += list.size();
    }
    return total;
}