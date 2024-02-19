#include <string>
using namespace std;

class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int oneCount{}, zeroCount{};
        for (auto x : s)
        {
            if (x == '1')
                ++oneCount;
            else
                ++zeroCount;
        }

        string res{};
        for (int i{1}; i <= oneCount - 1; ++i)
        {
            res += '1';
        }
        for (int i{1}; i <= zeroCount; ++i)
        {
            res += '0';
        }
        res += '1';
        return res;
    }
};