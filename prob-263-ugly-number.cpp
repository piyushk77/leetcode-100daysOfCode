#include <cmath>
using namespace std;

class Solution
{
public:
    bool isUgly(int n)
    {
        int num{n};
        int two{}, three{}, five{};
        while (n && (n % 2 == 0))
        {
            n /= 2;
            ++two;
        }

        while (n && (n % 3 == 0))
        {
            n /= 3;
            ++three;
        }

        while (n && (n % 5 == 0))
        {
            n /= 5;
            ++five;
        }

        if (num == pow(2, two) * pow(3, three) * pow(5, five))
            return true;
        return false;
    }
};