#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    size_t n;
    cin >> n;
    int64_t sum = 0;
    vector<int> temp(n);
    for (auto& i : temp) {
        cin >> i;
        sum += i;
    }
        
    int avg = sum / static_cast<int>(n);
    cout << count_if(temp.begin(), temp.end(), [avg](int x) { return x > avg; }) << endl;
    for (auto i = 0; i < temp.size(); ++i)
        if (temp[i] > avg)
            cout << i << " ";
}
