#include <vector>
using namespace std;

class Solution
{
public:
    int differenceOfSum(vector<int> &nums)
    {
        long long elementSum{}, digitSum{};
        for (auto x : nums)
        {
            elementSum += x;
            while (x)
            {
                int digit{x % 10};
                digitSum += digit;
                x /= 10;
            }
        }
        int res{static_cast<int>(elementSum - digitSum)};
        if (res < 0)
            return -res;
        return res;
    }
};