#include <string>
#include <set>
#include <map>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> res;
    for (auto item : m) {
        res.insert(item.second);
    }
    return res;
}
