#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n{static_cast<int>(nums.size()) - 1};
        return (nums[n] * nums[n - 1] - nums[0] * nums[1]);
    }
};