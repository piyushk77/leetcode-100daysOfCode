class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        long long num{1};
        while (num < n)
        {
            num *= 2;
        }
        if (num == n)
            return true;
        return false;
    }
};