class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        int temp{n};
        int product{1}, sum{};
        while (n)
        {
            int digit{n % 10};
            product *= digit;
            n /= 10;
        }
        while (temp)
        {
            int digit{temp % 10};
            sum += digit;
            temp /= 10;
        }
        return product - sum;
    }
};