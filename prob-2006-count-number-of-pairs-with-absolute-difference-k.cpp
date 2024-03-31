#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    int countKDifference(vector<int> &nums, int k)
    {
        int count{};
        for (int i{}; i < nums.size(); ++i)
        {
            for (int j{i + 1}; j < nums.size(); ++j)
            {
                if (abs(nums[i] - nums[j]) == k)
                    ++count;
            }
        }
        return count;
    }
};