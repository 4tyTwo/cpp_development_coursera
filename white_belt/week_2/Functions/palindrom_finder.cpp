#include <vector>

using namespace std;

bool IsPalindrom(string st) {
    int length = st.length();
    for (int i = 0; i < length / 2; ++i) {
        if (st[i] != st[length -1 - i]) {
            return false;
        }
    }
    return true;
}

vector<string> PalindromFilter(vector<string> v, int a) {
   vector<string> res;
   for (auto s : v) {
       if (IsPalindrom(s) && s.length() >= a) {
           res.push_back(s);
       }
   }
   return res;
}
