#include <vector>
using namespace std;

class Solution
{
public:
    int smallestRangeI(vector<int> &nums, int k)
    {
        int max{nums[0]}, min{nums[0]};
        for (auto x : nums)
        {
            if (max < x)
                max = x;
            if (min > x)
                min = x;
        }

        if (max - min <= 2 * k)
            return 0;
        else
            return (max - min - 2 * k);
    }
};