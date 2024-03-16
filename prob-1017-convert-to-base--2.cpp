#include <string>
using namespace std;

class Solution
{
public:
    inline int divide2(int num)
    {
        if (num < 0)
        {
            if ((-num) % 2 == 0)
                return num / -2;
            return ((-num / 2) + 1);
        }
        return (num / -2);
    }
    string baseNeg2(int n)
    {
        string res{};
        if (!n)
            res = "0";
        while (n)
        {
            int q{divide2(n)};
            int rem{n - (-2 * q)};
            res = to_string(rem) + res;
            n = q;
        }
        return res;
    }
};