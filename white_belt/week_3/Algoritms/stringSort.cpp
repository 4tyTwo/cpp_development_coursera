#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    vector<string> v;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), [](string a, string b) {
        // could use tolower instead
        transform(a.begin(), a.end(), a.begin(), ::tolower);
        transform(b.begin(), b.end(), b.begin(), ::tolower);
        return a < b;
    });
    for (const auto& i : v) {
        cout << i << " ";
    }
    return 0;
}
