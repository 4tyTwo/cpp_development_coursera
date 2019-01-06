#include <string>
#include <algorithm>

using namespace std;

class ReversibleString {
public:
    ReversibleString()
    {
        data = "";
    }

    ReversibleString(const string& st)
    {
        data = st;
    }

    string ToString() const
    {
        return data;
    }

    void Reverse()
    {
       reverse(data.begin(), data.end());
    }
private:
    string data;
};
