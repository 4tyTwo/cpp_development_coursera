#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string a, b,c ;
    cin >> a >> b >> c;
    vector<string> v = {a, b ,c};
    
    cout << *min_element(begin(v), end(v));
    return 0;
}