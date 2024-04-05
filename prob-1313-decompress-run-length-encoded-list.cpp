#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> decompressRLElist(vector<int> &nums)
    {
        vector<int> res;
        for (int i{}; i < static_cast<int>(nums.size()) - 1; i += 2)
        {
            for (int j{1}; j <= nums[i]; ++j)
                res.push_back(nums[i + 1]);
        }
        return res;
    }
};