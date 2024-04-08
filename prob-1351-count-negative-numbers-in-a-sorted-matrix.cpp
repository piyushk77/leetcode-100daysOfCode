#include <vector>
using namespace std;

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int count{};
        for (auto x : grid)
            for (auto y : x)
                if (y < 0)
                    ++count;
        return count;
    }
};