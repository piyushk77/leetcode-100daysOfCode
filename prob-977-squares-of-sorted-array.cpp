#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n{static_cast<int>(nums.size())};
        if (n == 1)
        {
            nums[0] *= nums[0];
            return nums;
        }

        int juncIndex{};
        while (juncIndex < n && nums[juncIndex] < 0)
            ++juncIndex;

        int i{-1}, j{juncIndex};
        if (juncIndex > 0)
            i = juncIndex - 1;

        vector<int> res;
        while (i >= 0 && j < n)
        {
            int leftSquare{nums[i] * nums[i]};
            int rightSquare{nums[j] * nums[j]};
            if (leftSquare < rightSquare)
            {
                res.push_back(leftSquare);
                --i;
            }
            else
            {
                res.push_back(rightSquare);
                ++j;
            }
        }

        for (int x{i}; x >= 0; --x)
        {
            res.push_back(nums[x] * nums[x]);
        }
        for (int y{j}; y < n; ++y)
        {
            res.push_back(nums[y] * nums[y]);
        }
        return res;
    }
};