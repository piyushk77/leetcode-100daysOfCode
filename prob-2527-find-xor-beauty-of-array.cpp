#include <vector>
using namespace std;

class Solution
{
public:
    int xorBeauty(vector<int> &nums)
    {
        int xorSum{};
        for (auto x : nums)
        {
            xorSum ^= x;
        }
        return (xorSum);
    }
};