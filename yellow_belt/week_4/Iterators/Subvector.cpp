#include <iostream>
#include <vector>

using namespace std;

void PrintVectorPart(const vector<int>& numbers)
{
    auto it = numbers.begin();
    for (it; it != numbers.end() && *it >= 0; ++it);
    while (it != numbers.begin())
    {
        --it;
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    PrintVectorPart({6, 1, 8, -5, 4});
    PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
    PrintVectorPart({6, 1, 8, 5, 4});
    return 0;
}
