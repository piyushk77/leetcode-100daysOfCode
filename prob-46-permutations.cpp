#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> mergeArr(int num, vector<vector<int>> arr)
    {
        vector<vector<int>> res;
        for (auto x : arr)
        {
            vector<int> temp;
            temp.push_back(num);
            for (auto y : x)
                temp.push_back(y);
            res.push_back(temp);
        }
        return res;
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        if (nums.size() == 1)
            return {{nums[0]}};
        if (nums.size() == 2)
        {
            return {{nums[0], nums[1]}, {nums[1], nums[0]}};
        }

        vector<vector<int>> res;
        for (int i{}; i < nums.size(); ++i)
        {
            vector<int> temp{nums};
            temp.erase(temp.begin() + i);
            vector<vector<int>> singlePerm{mergeArr(nums[i], permute(temp))};
            for (auto x : singlePerm)
                res.push_back(x);
        }
        return res;
    }
};