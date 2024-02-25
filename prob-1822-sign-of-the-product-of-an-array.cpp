#include <vector>
using namespace std;

class Solution
{
public:
    int arraySign(vector<int> &nums)
    {
        int negatives{};
        for (auto x : nums)
        {
            if (x == 0)
                return 0;
            else if (x < 0)
                ++negatives;
        }
        if (negatives % 2 == 0)
            return 1;
        return -1;
    }
};