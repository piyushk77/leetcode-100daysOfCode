#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        long long total{};
        for (auto x : nums)
            total += x;
        for (int i{}; i < nums.size(); ++i)
        {
            total -= nums[i];
            if (total > nums[i] && (static_cast<int>(nums.size()) - i + 1) >= 3)
                return total + nums[i];
        }
        return -1;
    }
};