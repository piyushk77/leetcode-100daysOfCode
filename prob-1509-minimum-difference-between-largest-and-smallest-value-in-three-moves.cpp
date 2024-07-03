#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minDifference(vector<int> &nums)
    {
        int n{static_cast<int>(nums.size())};
        if (n == 1 || n == 2 || n == 3 || n <= 0)
            return 0;

        // Sort the array in descending order
        sort(nums.begin(), nums.end(), greater<int>());
        int diff{};
        // All three changes in the beginning
        int high{nums[3]};
        int low{nums[n - 1]};
        diff = high - low;
        // Two at the beginning and one at the end
        high = nums[2];
        low = nums[n - 2];
        if (high - low < diff)
            diff = high - low;
        // One at the beginning and two at the end
        high = nums[1];
        low = nums[n - 3];
        if (high - low < diff)
            diff = high - low;
        // All three changes at the end
        high = nums[0];
        low = nums[n - 4];
        if (high - low < diff)
            diff = high - low;
        return diff;
    }
};