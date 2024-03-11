#include <vector>
using namespace std;

class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long res{};
        for (int i{}; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                long long n{};
                while (i < nums.size() && nums[i] == 0)
                {
                    ++n;
                    ++i;
                }
                --i;
                long long sum{n * (n + 1) / 2};
                res += sum;
            }
        }
        return res;
    }
};