class Solution
{
public:
    int countDigits(int num)
    {
        int n{num};
        int digits{};
        while (n)
        {
            int digit{n % 10};
            n /= 10;
            if (num % digit == 0)
                ++digits;
        }
        return digits;
    }
};