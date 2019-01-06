#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ifstream in("input.txt");
    if (in) {
        double v;
        cout << setprecision(3) << fixed;
        while (in >> v) {
                cout << v << endl;
            }
    }
   return 0;
}
