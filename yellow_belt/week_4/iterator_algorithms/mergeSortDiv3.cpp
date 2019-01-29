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
    RandomIt first_th = elements.begin() + range_len / 3;
    RandomIt second_th = first_th + range_len / 3;
    MergeSort(elements.begin(), first_th);
    MergeSort(first_th, second_th);
    MergeSort(second_th, elements.end());
    vector<typename RandomIt::value_type> tmp;
    merge(elements.begin(), first_th, first_th, second_th, back_inserter(tmp));
    merge(tmp.begin(), tmp.end(), second_th, elements.end(), range_begin);
}

int main()
{
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 3};
    MergeSort(begin(v), end(v));
    for (int x : v)
        cout << x << " ";
    cout << endl;
    return 0;
}
