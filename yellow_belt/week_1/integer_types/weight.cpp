#include <iostream>
#include <stdint.h>

using namespace std;

int main()
{
    /// looks weird, but grader only accepts upon using uint64_t on everything
    uint64_t density = 0;
    uint64_t n = 0, dimension = 0;
    uint64_t total = 0, subtotal = 0;
    cin >> n >> density;
    for (uint64_t i = 0; i < n; ++i)
    {
        subtotal = 1;
        for (uint64_t j = 0; j < 3; ++j)
        {
            cin >> dimension;
            subtotal *= dimension;
        }
        total += subtotal;    
    }
    total *= density;
    cout << total << endl;
}
