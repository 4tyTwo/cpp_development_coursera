#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ifstream in("input.txt");
    if (in) {
        int n = 0, m = 0, tmp;
        in >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                in >> tmp;
                in.ignore(1);
                cout << setw(10) << tmp;
                if (j != m -1)
                    cout << " ";
            }
            if (i != n -1)
                cout << endl;
        }
    }
   return 0;
}
