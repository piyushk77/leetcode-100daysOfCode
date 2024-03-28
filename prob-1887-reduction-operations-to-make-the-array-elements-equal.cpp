#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int reductionOperations(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        int min{nums.back()};
        if (min == nums[0])
            return 0;
        int count{};
        for (int i{}; i < nums.size(); ++i)
        {
            while ((i + 1) < nums.size() && nums[i] == nums[i + 1])
                ++i;
            if (nums[i] == min)
                break;
            // collapse
            count += i + 1;
        }
        return count;
    }
};