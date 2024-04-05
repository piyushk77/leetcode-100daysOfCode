#include <vector>
using namespace std;

class Solution
{
public:
    int countPairs(vector<int> &nums, int k)
    {
        int count{};
        for (int i{}; i < nums.size(); ++i)
        {
            for (int j{i + 1}; j < nums.size(); ++j)
            {
                if ((nums[i] == nums[j]) && ((i * j) % k == 0))
                    ++count;
            }
        }
        return count;
    }
};