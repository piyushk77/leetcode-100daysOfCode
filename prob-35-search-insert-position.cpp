#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int first{};
        int last{static_cast<int>(nums.size() - 1)};
        int mid{static_cast<int>((first + last) / 2)};
        if (target > nums[last])
            return last + 1;
        while (true)
        {
            if (target < nums[mid])
            {
                int check{mid};
                last = mid;
                mid = (first + last) / 2;
                if (mid == check)
                    return mid;
            }
            else if (target > nums[mid])
            {
                int check{mid};
                first = mid;
                mid = (first + last) / 2;
                if (mid == check)
                    return mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};