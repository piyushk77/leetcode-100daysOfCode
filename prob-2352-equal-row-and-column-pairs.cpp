#include <vector>
using namespace std;

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int n{static_cast<int>(grid.size())};
        int count{};
        for (int row{}; row < n; ++row)
        {
            for (int col{}; col < n; ++col)
            {
                bool flag{true};
                for (int i{}; i < n; ++i)
                {
                    if (grid[row][i] != grid[i][col])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    ++count;
            }
        }
        return count;
    }
};