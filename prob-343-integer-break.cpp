#include <cmath>
using namespace std;

class Solution
{
public:
    int integerBreak(int n)
    {
        long long maxProd{1};
        for (int k{2}; k <= n; ++k)
        {
            int max{static_cast<int>(
                round(static_cast<double>(n) / static_cast<double>(k)))};
            long long prod{1};
            prod *= pow(max, k - 1);
            prod *= (n - (max * (k - 1)));
            if (maxProd < prod)
                maxProd = prod;
        }
        return maxProd;
    }
};