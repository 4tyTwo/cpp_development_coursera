#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> BuildCharCounters(const string& st) {
    map<char, int> res;
    for (const char& c : st) {
        res[c]++;
    }
    return res;
}

int main() {
    int n;
    string word1, word2;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> word1 >> word2;
        if (BuildCharCounters(word1) == BuildCharCounters(word2)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
