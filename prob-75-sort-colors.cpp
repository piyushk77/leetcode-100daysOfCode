#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n{static_cast<int>(nums.size())};
        int i{}, j{};
        while (j < n)
        {
            if (!nums[j])
                swap(nums[i++], nums[j++]);
            else if (nums[j] == 1)
                ++j;
            else if (nums[j] == 2)
                swap(nums[j], nums[--n]);
        }
    }
};