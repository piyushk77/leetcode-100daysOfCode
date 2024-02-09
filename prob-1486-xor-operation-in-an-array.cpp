#include <vector>
using namespace std;

class Solution
{
public:
    int xorOperation(int n, int start)
    {
        vector<int> nums;
        for (int i{}; i < n; ++i)
        {
            nums.push_back(start + 2 * i);
        }
        int result{nums[0]};
        for (int i{1}; i < nums.size(); ++i)
            result ^= nums[i];
        return result;
    }
};