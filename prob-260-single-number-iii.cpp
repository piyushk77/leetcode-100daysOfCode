#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        // Get the xor of the two elements
        int xorSum{};
        for (auto x : nums)
            xorSum ^= x;
        // Find the diff bit
        int mask{1};
        while (!(mask & xorSum))
            mask <<= 1;
        // Find the two elements
        int first{}, second{};
        for (auto x : nums)
            if (x & mask)
                first ^= x;
            else
                second ^= x;
        return {first, second};
    }
};