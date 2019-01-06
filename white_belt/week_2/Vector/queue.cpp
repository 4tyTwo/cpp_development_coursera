#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

const int QUIET = 0;
const int WORRIED = 1;

void worry(vector<int>& v, int i) {
    v[i] = WORRIED;
}

void quiet(vector<int>& v, int i) {
    v[i] = QUIET;
}

void come(vector<int>& v, int n) {
    if (n > 0) {
        for (int i = 0; i < n; ++i) {
            v.push_back(QUIET);
        }
    }
    else {
        for (int i = 0; i < abs(n); ++i) {
            v.pop_back();
        }
    }
}

int worry_count(const vector<int>& v) {
    return accumulate(v.begin(), v.end(), 0);
}

int main() {
    int n, k;
    cin >> n;
    vector<int> v;
    string tmp;
    for (int i = 0 ; i < n; ++i) {
        cin >> tmp;
        if (tmp == "QUIET") {
            cin >> k;
            quiet(v, k);
        }
        if (tmp == "WORRY") {
            cin >> k;
            worry(v, k);
        }
        if (tmp == "COME") {
            cin >> k;
            come(v, k);
        }
        if (tmp == "WORRY_COUNT") {
            cout << worry_count(v) << endl;
        }
    }
    return 0;
}
