#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int lastIndex{static_cast<int>(nums.size() - 1)};
        if (k > nums.size())
        {
            k %= nums.size();
        }
        vector<int> newNums;
        for (int i{lastIndex - k + 1}; i < nums.size(); ++i)
        {
            newNums.push_back(nums[i]);
        }
        for (int i{}; i < lastIndex - k + 1; ++i)
        {
            newNums.push_back(nums[i]);
        }
        nums.clear();
        for (int i{}; i < newNums.size(); ++i)
            nums.push_back(newNums[i]);
    }
};