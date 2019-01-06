#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    ifstream in("input.txt");
    if (in) {
        string line;
        while (getline(in, line)) {
                cout << line << endl;
            }
    }
   return 0;
}
