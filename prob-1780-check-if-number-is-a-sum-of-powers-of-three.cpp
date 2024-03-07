#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        int i{};
        while (pow(3, i) <= n)
            ++i;
        vector<int> chart;
        for (int p{i}; p >= 0; --p)
        {
            chart.push_back(pow(3, p));
        }

        for (auto x : chart)
        {
            if (n >= x)
            {
                n -= x;
                if (n >= x)
                    return false;
                if (x == 0)
                    return true;
            }
        }

        return true;
    }
};