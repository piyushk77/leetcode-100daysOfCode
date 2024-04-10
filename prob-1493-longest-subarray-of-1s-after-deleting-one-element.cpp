#include <vector>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        vector<int> compress;
        for (int i{}; i < nums.size(); ++i)
        {
            if (nums[i])
            {
                int count{};
                while (i < nums.size() && nums[i])
                {
                    ++count;
                    ++i;
                }
                --i;
                compress.push_back(count);
            }
            else
            {
                compress.push_back(nums[i]);
            }
        }

        int n{static_cast<int>(compress.size())};
        int max{};
        if (n <= 3)
        {
            if (n == 1)
            {
                if (compress[0])
                    return compress[0] - 1;
                else
                    return compress[0];
            }
            else if (n == 2)
            {
                return compress[0] + compress[1];
            }
            else
            {
                return compress[0] + compress[1] + compress[2];
            }
        }
        else
        {
            for (int i{}; i < n - 2; ++i)
            {
                if (!compress[i + 1])
                {
                    if (max < (compress[i] + compress[i + 2]))
                        max = compress[i] + compress[i + 2];
                }
            }
        }

        return max;
    }
};