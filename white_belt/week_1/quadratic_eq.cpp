#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    if (a != 0) {
        // thus equation IS quadratic
        double d = (b * b) - (4 * a * c);
        if (d == 0)
            if (b == 0)
                cout << 0;
            else
                cout << -b / (2 * a);
        if (d > 0) {
            double x1 = (-b + sqrt(d))/(2 * a), x2 = (-b - sqrt(d))/(2 * a);
            cout << x1 << " " << x2;
        }
    }
    else {
        if (b != 0)
            cout << -c/b;
    }
    return 0;
}