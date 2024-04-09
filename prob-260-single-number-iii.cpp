#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        vector<int> bin1;
        vector<int> bin2;
        int result{};
        for (auto x : nums)
            result ^= x;

        int mask{1};
        while (!(result & mask))
        {
            mask <<= 1;
        }
        for (auto x : nums)
        {
            if ((x & mask))
                bin1.push_back(x);
            else
                bin2.push_back(x);
        }

        int res1{}, res2{};
        for (auto x : bin1)
            res1 ^= x;
        for (auto x : bin2)
            res2 ^= x;

        return {res1, res2};
    }
};