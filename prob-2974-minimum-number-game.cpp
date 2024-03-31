#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> numberGame(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n{static_cast<int>(nums.size())};
        int i{};
        vector<int> arr(n);
        while (i < n)
        {
            int alice{nums[i]};
            ++i;
            arr[i] = alice;
            int bob{nums[i]};
            ++i;
            arr[i - 2] = bob;
        }
        return arr;
    }
};