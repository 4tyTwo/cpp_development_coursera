#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
    int range_len = range_end - range_begin;
    if (range_len < 2)
        return;
    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    RandomIt middle = elements.begin() + range_len / 2;
    MergeSort(elements.begin(), middle);
    MergeSort(middle, elements.end());
    merge(elements.begin(), middle, middle, elements.end(), range_begin);
}

int main()
{
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
    MergeSort(begin(v), end(v));
    for (int x : v)
        cout << x << " ";
    cout << endl;
    return 0;
}
