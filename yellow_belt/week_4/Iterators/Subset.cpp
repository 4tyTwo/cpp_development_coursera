#include <iostream>
#include <vector>
#include <set>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border)
{
    auto it = elements.begin();
    for (it; it != elements.end() && *it <= border; ++it);
    vector<T> res;
    for (it; it != elements.end(); ++it)
        res.push_back(*it);
    return res;
}

int main()
{
    for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5))
        cout << x << " ";
    cout << endl;
    
    for (int x : FindGreaterElements(set<int>{1, 5, 9, 6}, 6))
        cout << x << " ";
    cout << endl;

    string to_find = "Python";
    cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
    return 0;
}
