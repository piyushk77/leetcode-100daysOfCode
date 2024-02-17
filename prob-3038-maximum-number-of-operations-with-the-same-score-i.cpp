#include <vector>
using namespace std;

class Solution
{
public:
    int maxOperations(vector<int> &nums)
    {
        int initialScore{nums[0] + nums[1]};
        int operations{};
        while (nums.size() > 1)
        {
            int score{nums[0] + nums[1]};
            nums.erase(nums.begin() + 0);
            nums.erase(nums.begin() + 0);
            if (score == initialScore)
                ++operations;
            else
                break;
        }
        return operations;
    }
};