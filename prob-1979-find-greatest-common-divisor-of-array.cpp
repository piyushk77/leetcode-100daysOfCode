#include <vector>
using namespace std;

class Solution
{
public:
    int gcd(int x, int y)
    {
        if (y % x == 0)
            return x;
        return gcd(y % x, x);
    }
    int findGCD(vector<int> &nums)
    {
        int min{nums[0]};
        int max{nums[0]};
        for (auto x : nums)
        {
            if (min > x)
                min = x;
            if (max < x)
                max = x;
        }
        return gcd(min, max);
    }
};