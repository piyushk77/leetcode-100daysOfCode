#include <vector>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int xorSum{};
        for (auto x : nums)
            xorSum ^= x;

        unsigned int mask{0b1000'0000'0000'0000'0000'0000'0000'0000};
        int count{};
        for (int i{}; i < 32; ++i)
        {
            unsigned int kbit{(k & mask) >> (32 - i - 1)};
            unsigned int numbit{(xorSum & mask) >> (32 - i - 1)};
            mask = mask >> 1;
            if (kbit != numbit)
                ++count;
        }
        return count;
    }
};