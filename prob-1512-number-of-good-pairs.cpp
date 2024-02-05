#include <vector>
using namespace std;

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int goodPairs{};
        for (int i{}; i < nums.size(); ++i)
        {
            for (int j{i + 1}; j < nums.size(); ++j)
            {
                if (nums[i] == nums[j])
                    ++goodPairs;
            }
        }
        return goodPairs;
    }
};