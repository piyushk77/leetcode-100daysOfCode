#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    inline int getCount(vector<int> subarray)
    {
        sort(subarray.begin(), subarray.end());
        int count{};
        for (int i{}; i < subarray.size(); ++i)
        {
            ++count;
            while ((i + 1 < subarray.size()) &&
                   (subarray[i + 1] == subarray[i]))
                ++i;
        }
        return count;
    }
    int sumCounts(vector<int> &nums)
    {
        int res{};
        for (int i{}; i < nums.size(); ++i)
        {
            vector<int> subarray;
            for (int j{i}; j < nums.size(); ++j)
            {
                subarray.push_back(nums[j]);
                int count{getCount(subarray)};
                res += (count * count);
            }
        }
        return res;
    }
};