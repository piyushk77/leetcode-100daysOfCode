#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<int> ans;
        for (int i{}; i < nums.size(); ++i)
        {
            int count{};
            for (int j{}; j < nums.size(); ++j)
            {
                if (nums[j] < nums[i])
                    ++count;
            }
            ans.push_back(count);
        }
        return ans;
    }
};