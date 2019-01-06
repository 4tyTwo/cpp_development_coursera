#include <vector>

using namespace std;

void Reverse(vector<int>& numbers) {
    int length = numbers.size();
    for (int i = 0; i < length / 2; ++i) {
        swap(numbers[i], numbers[length - 1 - i]);
    }
}
