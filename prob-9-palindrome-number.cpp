class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }

        long long temp{x};
        long long rev{};
        while (temp)
        {
            long long unitDigit{temp % 10};
            rev = rev * 10 + unitDigit;
            temp /= 10;
        }

        if (rev == x)
            return true;

        return false;
    }
};