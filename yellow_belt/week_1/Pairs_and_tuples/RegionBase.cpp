#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <map>

using namespace std;

/// should be commented, before sending to grader, as we actually rely on data structures used by grader
// enum class Lang 
// {
//   DE, FR, IT
// };

// struct Region 
// {
//     string std_name;
//     string parent_std_name;
//     map<Lang, string> names;
//     int64_t population;
// };

bool operator < (const Region& l, const Region& r) 
{
    return tie(l.std_name, l.parent_std_name, l.names, l.population) < tie(r.std_name, r.parent_std_name, r.names, r.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions) 
{
    int result = 0;
    map<Region, int> repetion_count;
    for (const Region& region : regions) {
        result = max(result, ++repetion_count[region]);
    }
    return result;
}

int main() 
{
  cout << FindMaxRepetitionCount({
      {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      },
  }) << endl;
  
  cout << FindMaxRepetitionCount({
      {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Toulouse",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          31
      },
  }) << endl;
  
  return 0;
}
