#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// I really didn't want to use sort
class SortedStrings {
public:
  void AddString(const string& s)
  {
    ++sorted_strings[s];
  }

  vector<string> GetSortedStrings()
  {
    vector<string> res;
    for (auto item : sorted_strings) {
        for (int i = 0; i < item.second; ++i) {
            res.push_back(item.first);
        }
    }
    return res;
  }
private:
  map<string, int> sorted_strings;
};
