#include <vector>
using namespace std;

class Solution
{
public:
    int projectionArea(vector<vector<int>> &grid)
    {
        int n{static_cast<int>(grid.size())};
        int xyArea{}, xzArea{}, yzArea{};
        for (int i{}; i < n; ++i)
        {
            int max{}, max2{};
            for (int j{}; j < n; ++j)
            {
                if (grid[i][j])
                    ++xyArea;
                if (grid[i][j] > max)
                    max = grid[i][j];
                if (grid[j][i] > max2)
                    max2 = grid[j][i];
            }
            xzArea += max;
            yzArea += max2;
        }
        return xyArea + xzArea + yzArea;
    }
};