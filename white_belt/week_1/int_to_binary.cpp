#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, highest_power = 0;
    cin >> a;
    while (pow(2, highest_power) <= a) {
        highest_power++;
    }
    for (int i = highest_power - 1; i >= 0; i--) {
        if (a >= pow(2, i)) {
            a -= (int) pow(2, i);
            cout << 1;
        }
        else {
            cout << 0;
        }
    }
    return 0;
}
