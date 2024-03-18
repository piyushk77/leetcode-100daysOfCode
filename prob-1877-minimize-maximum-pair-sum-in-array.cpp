#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int max{}, n{static_cast<int>(nums.size())};
        for (int i{}, j{n - 1}; i < (n / 2); ++i, --j)
        {
            if (max < (nums[i] + nums[j]))
                max = nums[i] + nums[j];
        }
        return max;
    }
};