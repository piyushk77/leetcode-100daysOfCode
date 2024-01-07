#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> factorize(vector<int> arr)
    {
        vector<int> factArr;
        for (auto x : arr)
        {
            for (int i{2}; x != 1; ++i)
            {
                if (x % i == 0)
                {
                    factArr.push_back(i);
                    x /= i;
                    i = 1;
                }
            }
        }
        return factArr;
    }

    vector<int> factVector(int begin, int end)
    {
        vector<int> fact;
        if (end > begin || begin == 0)
        {
            fact.push_back(1);
            return fact;
        }
        for (int i{begin}; i >= end; --i)
        {
            fact.push_back(i);
        }
        return fact;
    }

    vector<int> divide(vector<int> num, vector<int> den)
    {
        if (den.size() == 1)
            return num;
        for (int i{}; i < den.size(); ++i)
        {
            if (den[i] == 1)
            {
                den.erase(den.begin() + i);
                --i;
                continue;
            }
            int divisor{den[i]};
            for (int j{}; j < num.size(); ++j)
            {
                if (num[j] % divisor == 0)
                {
                    num[j] /= divisor;
                    den.erase(den.begin() + i);
                    --i;
                    break;
                }
            }
        }
        if (den.size())
        {
            vector<int> factDen{factorize(den)};
            return divide(num, factDen);
        }
        return num;
    }

    int uniquePaths(int m, int n)
    {
        --m, --n;
        vector<int> numerator{factVector(m + n, (m >= n ? m + 1 : n + 1))};
        vector<int> denominator{factVector((m <= n ? m : n), 1)};
        vector<int> quotient{divide(numerator, denominator)};

        int paths{1};
        for (auto x : quotient)
            paths *= x;

        return paths;
    }
};