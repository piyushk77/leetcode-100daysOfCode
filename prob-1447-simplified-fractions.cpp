#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int hcf(int a, int b)
    {
        if (a == 1)
            return 1;
        if (b % a == 0)
            return a;
        return hcf(b % a, a);
    }
    vector<string> genCoprimesFractions(int n)
    {
        vector<string> res;
        for (int i{1}; i < n; ++i)
        {
            if (hcf(i, n) == 1)
            {
                string fraction{to_string(i) + "/" + to_string(n)};
                res.push_back(fraction);
            }
        }
        return res;
    }
    vector<string> simplifiedFractions(int n)
    {
        if (n == 1)
            return {};
        vector<string> mainPrimes{genCoprimesFractions(n)};
        vector<string> otherPrimes{simplifiedFractions(n - 1)};
        for (auto x : mainPrimes)
        {
            otherPrimes.push_back(x);
        }
        return otherPrimes;
    }
};