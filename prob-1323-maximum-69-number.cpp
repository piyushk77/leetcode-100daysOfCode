#include <cmath>
using namespace std;

class Solution
{
public:
    int maximum69Number(int num)
    {
        int tempNum{num};
        int digits{};
        while (tempNum)
        {
            tempNum /= 10;
            ++digits;
        }

        int res{};
        bool flag{true};

        for (int i{1}; i <= digits; ++i)
        {
            int divider{static_cast<int>(pow(10, digits - i))};
            int digit{num / divider};
            digit %= 10;

            if (digit == 6 && flag)
            {
                flag = false;
                res = res * 10 + 9;
                ++i;
                while (i <= digits)
                {
                    divider = pow(10, digits - i);
                    digit = num / divider;
                    digit %= 10;
                    res = res * 10 + digit;
                    ++i;
                }
            }
            else
                res = res * 10 + digit;
        }

        return res;
    }
};