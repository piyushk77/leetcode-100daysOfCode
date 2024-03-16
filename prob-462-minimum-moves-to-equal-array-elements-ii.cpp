#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n{static_cast<int>(nums.size())};
        int median{};
        if (n % 2)
            median = nums[((n + 1) / 2) - 1];
        else
            median = (nums[(n / 2) - 1] + nums[(n / 2)]) / 2;
        int steps{};
        for (auto x : nums)
        {
            if (x < median)
                steps += median - x;
            else
                steps += x - median;
        }
        return steps;
    }
};