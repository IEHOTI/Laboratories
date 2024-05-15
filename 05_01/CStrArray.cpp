#include "CStrArray.h"
CStrArray::CStrArray(int X) {
	x = X;
	a = new CStr[x];
}
CStrArray::~CStrArray() {
	delete[] a;
}
CStr& CStrArray::operator[](int X) {
	return a[X];
}
void CStrArray::sort_by_content() {
	int i = 0;
    CStr y;
    int l = 0, r = x - 1, f = 1;
    while ((l < r) && f > 0) {
        f = 0;
        for (int i = l; i < r; i++) {
            if (a[i] > a[i + 1]) {
                y = a[i];
                a[i] = a[i + 1];
                a[i + 1] = y;
                f = 1;
            }
        }
        r--;
        for (int i = r; i > l; i--) {
            if (a[i - 1] > a[i]) {
                y = a[i];
                a[i] = a[i - 1];
                a[i - 1] = y;
                f = 1;
            }
        }
        l++;
    }
}
void CStrArray::sort_by_length() {
    CStr y;
    int l = 0, r = x - 1, f = 1;
    while ((l < r) && f > 0) {
        f = 0;
        for (int i = l; i < r; i++) {
            if (a[i].get_length() > a[i + 1].get_length()) {
                y = a[i];
                a[i] = a[i + 1];
                a[i + 1] = y;
                f = 1;
            }
        }
        r--;
        for (int i = r; i > l; i--) {
            if (a[i - 1].get_length() > a[i].get_length()) {
                y = a[i];
                a[i] = a[i - 1];
                a[i - 1] = y;
                f = 1;
            }
        }
        l++;
    }
}
int CStrArray::bin_search(const char* B) {
    CStr A;
    A = B;
        int l = 0, r = x - 1, m;
        while (r > l) {
            m = (r + l) / 2;
            if (A > a[m])
                l = m + 1;
            else if (a[m] > A)
                r = m - 1;
            else return m;
        }
        if (a[l] == A)
            return l;
        return -1;
}
bool CStrArray::check_sort() {
    for (int i = 0; i < x-1; i++) {
        if (a[i] > a[i + 1]) return false;
    }
    return true;
}