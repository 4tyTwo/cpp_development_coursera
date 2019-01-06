#include <iostream>

using namespace std;

int main() {
    int a, b, start;
    cin >> a >> b;
    if ( a % 2 == 1) {
        start = a + 1;
    }
    else {
        start = a;
    }
    for (int i = start; i <= b; i+=2) {
        cout << i;
        if ( b - i >= 2) {
            cout << " ";
        }
    }
    return 0;
}