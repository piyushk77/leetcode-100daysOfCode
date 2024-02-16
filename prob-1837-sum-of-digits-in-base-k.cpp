class Solution
{
public:
    int sumBase(int n, int k)
    {
        int sum{};
        while (n)
        {
            int bit{n % k};
            sum += bit;
            n /= k;
        }
        return sum;
    }
};