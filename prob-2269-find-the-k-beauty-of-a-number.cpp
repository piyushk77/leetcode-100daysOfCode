#include <cmath>
using namespace std;
class Solution
{
public:
    int subNum(int num, int i, int len, int digits)
    {
        long n{num};
        if (i + len - 1 >= digits)
            return -1;
        long divisor{static_cast<long>(pow(10, digits - (i + len)))};
        n /= divisor;
        long modulus{static_cast<long>(pow(10, len))};
        n %= modulus;
        return static_cast<int>(n);
    }
    int divisorSubstrings(int num, int k)
    {
        int digits{};
        int temp{num};
        while (temp != 0)
        {
            temp /= 10;
            ++digits;
        }
        int kBeauty{};
        for (int i{}; i <= digits - k; ++i)
        {
            int sub{subNum(num, i, k, digits)};
            if (sub == 0)
                continue;
            if (num % sub == 0)
                ++kBeauty;
        }
        return kBeauty;
    }
};