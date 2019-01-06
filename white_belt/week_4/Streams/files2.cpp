#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    ifstream in("input.txt");
    if (in) {
        ofstream out("output.txt");
        string line;
        while (getline(in, line)) {
                out << line << endl;
            }
    }
   return 0;
}
