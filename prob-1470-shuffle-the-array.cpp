#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        vector<int> arr;
        for (int i{}, j{n}; i < n; ++i, ++j)
        {
            arr.push_back(nums[i]);
            arr.push_back(nums[j]);
        }
        return arr;
    }
};