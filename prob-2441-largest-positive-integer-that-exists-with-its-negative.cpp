#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int i{}, j{static_cast<int>(nums.size()) - 1};
        while (i < nums.size() && j >= 0 && nums[i] < 0 && nums[j] > 0)
        {
            if (abs(nums[i]) == nums[j])
                return nums[j];
            else if (abs(nums[i]) < nums[j])
                --j;
            else
                ++i;
        }
        return -1;
    }
};