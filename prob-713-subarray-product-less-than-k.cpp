#include <vector>
using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int count{};
        for (int i{}; i < nums.size(); ++i)
        {
            int prod{1};
            for (int j{i}; j < nums.size(); ++j)
            {
                prod *= nums[j];
                if (prod < k)
                    ++count;
                else
                    break;
            }
        }
        return count;
    }
};