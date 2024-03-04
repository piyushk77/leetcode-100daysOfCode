#include <vector>
using namespace std;

class Solution
{
public:
    int triangularSum(vector<int> &nums)
    {
        int n{static_cast<int>(nums.size())};
        if (n == 1)
            return nums[0];
        vector<int> newNums;
        for (int i{}; i < n - 1; ++i)
            newNums.push_back((nums[i] + nums[i + 1]) % 10);
        return triangularSum(newNums);
    }
};