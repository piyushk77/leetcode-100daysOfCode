#include <vector>
using namespace std;

class Solution
{
public:
    int countPairs(vector<int> &nums, int target)
    {
        int count{};
        int n{static_cast<int>(nums.size())};
        for (int i{}; i < n - 1; ++i)
        {
            for (int j{i + 1}; j < n; ++j)
            {
                if ((nums[i] + nums[j]) < target)
                    ++count;
            }
        }
        return count;
    }
};