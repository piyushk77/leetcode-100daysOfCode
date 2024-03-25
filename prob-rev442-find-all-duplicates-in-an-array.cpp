#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> ans;
        for (auto x : nums)
        {
            int num{nums[abs(x) - 1]};
            if (num > 0)
            {
                nums[abs(x) - 1] *= -1;
            }
            else
                ans.push_back(abs(x));
        }
        return ans;
    }
};