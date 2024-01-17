#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        for (int i{}; i < nums.size(); ++i)
        {
            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            {
                nums.erase(nums.begin() + i);
            }
        }
        return nums.size();
    }
};