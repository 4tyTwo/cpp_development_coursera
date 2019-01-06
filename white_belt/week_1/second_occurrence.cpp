#include <iostream>
#include <string>

using namespace std;

int main() {
    string st;
    int pos;
    cin >> st;
    pos = st.find_first_of('f', 0);
    if (pos == -1) {
        cout << -2;
    }
    else {
        pos = st.find_first_of('f', pos + 1);
        if (pos == -1) {
            cout << -1;
        }
        else {
            cout << pos;
        }
    }
    return 0;
}