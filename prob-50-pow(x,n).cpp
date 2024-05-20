class Solution
{
public:
    double myPow(double x, long long n)
    {
        if (n == 0)
            return 1.0;
        if (n == 1)
            return x;
        if (n == -1)
            return 1 / x;
        if (n % 2)
        {
            if (n > 0)
                return x * myPow(x, n - 1);
            else
                return myPow(x, n + 1) * (1 / x);
        }
        else
        {
            double temp{myPow(x, n / 2)};
            return temp * temp;
        }
    }
};