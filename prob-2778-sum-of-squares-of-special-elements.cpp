#include <vector>
using namespace std;

class Solution
{
public:
    int sumOfSquares(vector<int> &nums)
    {
        int sum{};
        int n{static_cast<int>(nums.size())};
        for (int i{}; i < n; ++i)
        {
            if ((n % (i + 1)) == 0)
            {
                sum = sum + nums[i] * nums[i];
            }
        }
        return sum;
    }
};