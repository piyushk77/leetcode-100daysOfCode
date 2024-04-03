#include <vector>
using namespace std;

class Solution
{
public:
    int maximizeSum(vector<int> &nums, int k)
    {
        int max{};
        for (auto x : nums)
            if (max < x)
                max = x;
        int res{(2 * max + k - 1) * k / 2};
        return res;
    }
};