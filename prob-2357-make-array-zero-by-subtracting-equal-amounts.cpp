#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> indiv;
        for (int i{}; i < nums.size(); ++i)
        {
            int currentNum{nums[i]};
            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            {
                ++i;
            }
            indiv.push_back(currentNum);
        }
        if (indiv[0] == 0)
            return indiv.size() - 1;
        return indiv.size();
    }
};