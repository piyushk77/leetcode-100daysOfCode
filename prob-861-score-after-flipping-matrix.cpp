#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    int toBin(vector<vector<int>> grid, int row)
    {
        int num{};
        int n{static_cast<int>(grid[row].size())};
        for (int i{}; i < n; ++i)
        {
            num += grid[row][i] * pow(2, n - i - 1);
        }
        return num;
    }
    void flipRow(vector<vector<int>> &grid, int row)
    {
        for (int i{}; i < grid[row].size(); ++i)
            if (grid[row][i])
                grid[row][i] = 0;
            else
                grid[row][i] = 1;
    }
    void selectiveFlipCol(vector<vector<int>> &grid, int col)
    {
        int ones{}, zeros{};
        for (int i{}; i < grid.size(); ++i)
        {
            if (grid[i][col])
                ++ones;
            else
                ++zeros;
        }
        if (zeros > ones)
        {
            for (int i{}; i < grid.size(); ++i)
            {
                if (grid[i][col])
                    grid[i][col] = 0;
                else
                    grid[i][col] = 1;
            }
        }
    }
    int matrixScore(vector<vector<int>> &grid)
    {
        for (int i{}; i < grid.size(); ++i)
        {
            if (!grid[i][0])
                flipRow(grid, i);
        }
        for (int i{}; i < grid[0].size(); ++i)
        {
            selectiveFlipCol(grid, i);
        }
        int sum{};
        for (int i{}; i < grid.size(); ++i)
        {
            sum += toBin(grid, i);
        }
        return sum;
    }
};