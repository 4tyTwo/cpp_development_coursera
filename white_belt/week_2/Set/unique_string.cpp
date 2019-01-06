#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n, stop_count;
    cin >> n;
    vector<string> strings;
    strings.resize(n);
    for (int i = 0 ; i < n; ++i) {
        cin >> strings[i];
    }
    set<string> s(strings.begin(), strings.end());
    cout << s.size() << endl;
    return 0;
}
