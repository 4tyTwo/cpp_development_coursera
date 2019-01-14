#include <vector>
#include <map>
#include <utility>

using namespace std;

template <typename T>
T Sqr(const T& x);

template <typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& x);

template <typename T>
vector<T> Sqr(const vector<T>& c);

template <typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>& c);
