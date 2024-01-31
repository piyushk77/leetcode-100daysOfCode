#include <vector>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int result{};
        for (auto x : nums)
        {
            result ^= x;
        }
        return result;
    }
};