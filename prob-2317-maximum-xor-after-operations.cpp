#include <vector>
using namespace std;

class Solution
{
public:
    int maximumXOR(vector<int> &nums)
    {
        int res{};
        for (auto n : nums)
            res |= n;
        return res;
    }
};