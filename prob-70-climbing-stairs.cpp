class Solution
{
public:
    int climbStairs(int n)
    {
        int first{1}, second{2};
        if (n == 1)
            return first;
        if (n == 2)
            return second;
        int sum{};
        for (int i{3}; i <= n; ++i)
        {
            sum = first + second;
            first = second;
            second = sum;
        }
        return sum;
    }
};