#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border)
{
    // auto greater_equal = lower_bound(numbers.begin(), numbers.end(), border); 
    // FUN FACT: 
    // commented algorithm has linear complexity
    // but uncommented has logarithmic complexity
    auto greater_equal = numbers.lower_bound(border);
    if (greater_equal == numbers.begin())
        return greater_equal;
    auto lesser = prev(greater_equal);
    if (greater_equal == numbers.end())
        return lesser;
    return abs(border - *lesser) <= abs(border - *greater_equal) ? lesser : greater_equal;
}

int main() {
  set<int> numbers = {1, 4, 6};
  cout <<
      *FindNearestElement(numbers, 0) << " " <<
      *FindNearestElement(numbers, 3) << " " <<
      *FindNearestElement(numbers, 5) << " " <<
      *FindNearestElement(numbers, 6) << " " <<
      *FindNearestElement(numbers, 100) << endl;
      
  set<int> empty_set;
  
  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}
