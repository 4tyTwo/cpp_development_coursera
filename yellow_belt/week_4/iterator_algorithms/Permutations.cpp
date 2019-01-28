#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>  

using namespace std;

int inc()
{ 
    static int i = 1;
    return i++;
}

int factorial(int n)
{
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

vector<vector<int>> getAllPermutations(int n)
{
    vector<int> v(n);
    generate(v.begin(), v.end(), inc);
    vector<vector<int>> res(factorial(n));
    reverse(v.begin(), v.end());
    auto first_permutation = v;
    int curr = 0;
    do
    {
        res[curr++] = v;
        prev_permutation(v.begin(), v.end());
    } while (v != first_permutation);
    return res;
}

int main()
{
    int n;
    cin >> n;
    auto res = getAllPermutations(n);
    for (const auto& vec : res)
    {
        for (const auto& elem : vec)
            cout << elem << " ";
        cout << endl;
    }
    return 0;
}
