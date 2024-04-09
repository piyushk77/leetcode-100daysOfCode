#include <cmath>
using namespace std;

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        int p{};
        while (pow(3, p) < n)
            ++p;
        if (pow(3, p) == n)
            return true;
        return false;
    }
};