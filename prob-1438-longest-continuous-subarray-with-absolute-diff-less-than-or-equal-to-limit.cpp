#include <vector>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        int n{static_cast<int>(nums.size())};
        int i{}, j{};
        int low{nums[0]}, high{nums[0]};
        int length{};
        int maxLength{};
        while (j < n)
        {
            if (low <= nums[j] && nums[j] <= high)
            {
                ++length;
                ++j;
            }
            else if (nums[j] < low)
            {
                if (high - nums[j] <= limit)
                {
                    low = nums[j];
                    ++length;
                    ++j;
                }
                else
                {
                    if (maxLength < length)
                        maxLength = length;
                    length = 0;
                    low = high = nums[j];
                    i = j - 1;
                    while (i >= 0)
                        if (nums[i] - low <= limit)
                        {
                            if (nums[i] > high)
                                high = nums[i];
                            ++length;
                            --i;
                        }
                        else
                            break;
                    ++i;
                }
            }
            else
            {
                if (nums[j] - low <= limit)
                {
                    high = nums[j];
                    ++length;
                    ++j;
                }
                else
                {
                    if (maxLength < length)
                        maxLength = length;
                    length = 0;
                    low = high = nums[j];
                    i = j - 1;
                    while (i >= 0)
                        if (high - nums[i] <= limit)
                        {
                            if (nums[i] < low)
                                low = nums[i];
                            ++length;
                            --i;
                        }
                        else
                            break;
                    ++i;
                }
            }
        }
        if (maxLength < length)
            maxLength = length;
        return maxLength;
    }
};