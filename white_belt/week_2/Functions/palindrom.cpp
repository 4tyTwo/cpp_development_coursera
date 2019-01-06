#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom(string st) {
    int length = st.length();
    for (int i = 0; i < length / 2; ++i) {
        if (st[i] != st[length -1 - i]) {
            return false;
        }
    }
    return true;
}
