#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n{static_cast<int>(nums.size())};
        for (int i{}; i < n; ++i)
        {
            if ((n - i) <= nums[i])
            {
                if (i == 0)
                    return n - i;
                else if ((n - i) > nums[i - 1])
                    return n - i;
            }
        }
        return -1;
    }
};