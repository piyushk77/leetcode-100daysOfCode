#include <vector>
using namespace std;

class Solution
{
public:
    int recXorSum(vector<int> &nums, int n, int i, int sum)
    {
        if (i >= n)
            return sum;
        return recXorSum(nums, n, i + 1, sum) + recXorSum(nums, n, i + 1, sum ^ nums[i]);
    }
    int subsetXORSum(vector<int> &nums)
    {
        int n{static_cast<int>(nums.size())};
        return recXorSum(nums, n, 0, 0);
    }
};