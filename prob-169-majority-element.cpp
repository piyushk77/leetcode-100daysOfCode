#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int maxCount{};
        int n{};
        for (int i{}; i < nums.size(); ++i)
        {
            int count{1};
            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            {
                ++i;
                ++count;
            }
            if (maxCount < count)
            {
                maxCount = count;
                n = nums[i];
            }
        }
        return n;
    }
};