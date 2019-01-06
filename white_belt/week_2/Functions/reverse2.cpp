#include <vector>
using namespace std;

 vector<int> Reversed(const vector<int>& v) {
     vector<int> res;
     for (auto i : v){
         res.insert(begin(res), i);
     }
     return res;
 }
