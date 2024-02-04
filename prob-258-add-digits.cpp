class Solution
{
public:
    bool isOneDigit(int n)
    {
        if (n / 10 == 0)
            return true;
        return false;
    }
    int addDigits(int num)
    {
        while (!isOneDigit(num))
        {
            int sum{};
            while (num)
            {
                int digit{num % 10};
                sum += digit;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};