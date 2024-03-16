#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string optimalDivision(vector<int> &nums)
    {
        string res{to_string(nums[0])};
        int n{static_cast<int>(nums.size())};
        if (n == 1)
            return res;
        if (n == 2)
        {
            res += ("/" + to_string(nums[1]));
            return res;
        }
        res += "/(";
        for (int i{1}; i < n - 1; ++i)
        {
            res += (to_string(nums[i]) + "/");
        }
        res += (to_string(nums[n - 1]) + ")");
        return res;
    }
};