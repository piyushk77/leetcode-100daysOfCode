#include <vector>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        vector<int> markers;
        for (int i{}; i <= nums.size(); ++i)
        {
            markers.push_back(i);
        }
        for (auto x : nums)
        {
            markers[x] = -1;
        }
        for (auto y : markers)
            if (y != -1)
                return y;
        return -2;
    }
};