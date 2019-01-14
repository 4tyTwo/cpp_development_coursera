#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

template <typename T> T Sqr(const T& x);
template <typename First, typename Second> pair<First, Second> Sqr(const pair<First, Second>& x);
template <typename T> vector<T> Sqr(const vector<T>& c);
template <typename Key, typename Value> map<Key, Value> Sqr(const map<Key, Value>& c);

template <typename T>
T Sqr(const T& x) { return x * x; }

template <typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& x) { return make_pair(Sqr(x.first), Sqr(x.second)); };

template <typename T>
vector<T> Sqr(const vector<T>& c)
{
    vector<T> res;
    for (const auto& i : c)
        res.push_back(Sqr(i));
    return res;
}

template <typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>& c)
{
    map<Key, Value> res;
    for (const auto& item : c)
        res[item.first] = Sqr(item.second);
    return res;
}


// int main()
// {
//     vector<int> v = {1, 2, 3};
//     cout << "vector:";
//     for (int x : Sqr(v))
//         cout << ' ' << x;
//     cout << endl;

//     map<int, pair<int, int>> map_of_pairs = {
//         {4, {2, 2}},
//         {7, {4, 3}}
//     };
//     cout << "map of pairs:" << endl;
//     for (const auto& x : Sqr(map_of_pairs))
//         cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
// }
