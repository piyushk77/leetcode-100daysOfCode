class Solution
{
public:
    int totalMoney(int n)
    {
        int weeks{n / 7};
        int i{1}, total{};
        for (; i <= weeks; ++i)
        {
            total += 7 * (2 * i + 6) / 2;
        }
        for (int day{1}; day <= (n % 7); ++day, ++i)
            total += i;
        return total;
    }
};