#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
    {
        const int bitSize{32};
        unsigned int numsXor{};
        for (auto x : nums)
        {
            numsXor ^= x;
        }
        int n{static_cast<int>(nums.size())};
        vector<int> res;
        for (int i{}; i < n; ++i)
        {
            unsigned int k{~numsXor};
            k = k << (bitSize - maximumBit);
            k = k >> (bitSize - maximumBit);
            res.push_back(k);
            numsXor = numsXor ^ nums[n - i - 1];
        }
        return res;
    }
};