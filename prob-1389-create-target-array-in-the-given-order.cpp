#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> insert(int num, int pos, vector<int> &nums)
    {
        vector<int> ans;
        for (int i{}; i < pos; ++i)
            ans.push_back(nums[i]);
        ans.push_back(num);
        for (int i{pos}; i < nums.size(); ++i)
            ans.push_back(nums[i]);
        return ans;
    }
    vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
    {
        vector<int> ans;
        for (int i{}; i < nums.size(); ++i)
        {
            ans = insert(nums[i], index[i], ans);
        }
        return ans;
    }
};