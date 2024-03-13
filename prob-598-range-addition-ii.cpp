#include <limits.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int>> &ops)
    {
        if (ops.size() == 0)
            return m * n;
        int maxX{INT_MAX}, maxY{INT_MAX};
        for (auto x : ops)
        {
            if (x[0] < maxX)
                maxX = x[0];
            if (x[1] < maxY)
                maxY = x[1];
        }
        return maxX * maxY;
    }
};