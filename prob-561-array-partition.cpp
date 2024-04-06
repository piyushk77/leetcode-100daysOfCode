#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int sum{};
        for (int i{1}; i < nums.size(); i += 2)
        {
            sum += (nums[i - 1] < nums[i] ? nums[i - 1] : nums[i]);
        }
        return sum;
    }
};