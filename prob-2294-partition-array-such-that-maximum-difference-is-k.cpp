#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int partitionArray(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int count{};
        for (int i{}; i < nums.size(); ++i)
        {
            int num{nums[i] + k};
            while (i < nums.size() && nums[i] <= num)
                ++i;
            --i;
            ++count;
        }
        return count;
    }
};