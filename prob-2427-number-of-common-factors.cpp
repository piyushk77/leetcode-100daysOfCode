#include <cmath>
using namespace std;

class Solution
{
public:
    int commonFactors(int a, int b)
    {
        int x{min(a, b)};
        int count{};
        for (int i{1}; i <= x; ++i)
        {
            if (a % i == 0 && b % i == 0)
                ++count;
        }
        return count;
    }
};