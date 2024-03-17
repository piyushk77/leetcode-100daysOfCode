#include <vector>
using namespace std;

class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        vector<int> westEastMax;
        vector<int> northSouthMax;
        int n{static_cast<int>(grid.size())};
        for (int i{}; i < n; ++i)
        {
            int max{};
            for (int j{}; j < n; ++j)
            {
                if (max < grid[i][j])
                    max = grid[i][j];
            }
            westEastMax.push_back(max);
        }
        for (int i{}; i < n; ++i)
        {
            int max{};
            for (int j{}; j < n; ++j)
            {
                if (max < grid[j][i])
                    max = grid[j][i];
            }
            northSouthMax.push_back(max);
        }
        int sum{};
        for (int i{}; i < n; ++i)
        {
            for (int j{}; j < n; ++j)
            {
                sum += min(westEastMax[i], northSouthMax[j]) - grid[i][j];
            }
        }
        return sum;
    }
};