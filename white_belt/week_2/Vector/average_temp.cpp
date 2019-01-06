#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

void print_vector(const vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        if (i != v.size() - 1){
            cout << v[i] << " ";
        }
        else {
            cout << v[i];
        }
    }
}

int average(const vector<int>& v) {
    return accumulate(v.begin(), v.end(), 0) / v.size();
}

vector<int> higher_than_average_indexes(const vector<int>& v) {
    int avg = average(v);
    vector<int> res;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > avg) {
            res.push_back(i);
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n), res;
    for (int i = 0 ; i < n; ++i) {
        cin >> v[i];
    }
    res = higher_than_average_indexes(v);
    cout << res.size() << endl;
    print_vector(res);
    return 0;
}
