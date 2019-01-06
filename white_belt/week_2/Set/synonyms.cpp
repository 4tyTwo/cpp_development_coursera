#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

void add(map<string, set<string>>& dict, const string& word1, const string& word2) {
    dict[word1].insert(word2);
    dict[word2].insert(word1);
}

void count(const map<string, set<string>>& dict, const string& word) {
    if (dict.count(word) > 0) {
        cout << dict.find(word)->second.size() << endl;
    }
    else {
        cout << 0 << endl;
    }
}

void check(const map<string, set<string>>& dict, const string& word1, const string& word2) {
    if (dict.count(word1) > 0 && dict.count(word2) > 0) {
        if (dict.find(word1)->second.count(word2) > 0) {
            cout << "YES" << endl;
            return;
        }  
    }
    cout << "NO" << endl;
}

int main() {
    int n;
    cin >> n;
    string tmp, word1, word2;
    map<string, set<string>> dict;
    for (int i = 0 ; i < n; ++i) {
        cin >> tmp;
        if (tmp == "ADD") {
            cin >> word1 >> word2;
            add(dict, word1, word2);
        }
        if (tmp == "COUNT") {
            cin >> word1;
            count(dict, word1);
        }
        if (tmp == "CHECK") {
            cin >> word1 >> word2;
            check(dict, word1, word2);
        }
    }
    return 0;
}
