#include <cmath>
using namespace std;

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        int x{};
        while (n > pow(4, x))
        {
            ++x;
        }
        if (n == pow(4, x))
            return true;
        return false;
    }
};