#include <vector>
using namespace std;

class Solution
{
public:
    int sumHourGlass(vector<vector<int>> &grid, int row, int col)
    {
        int sum{};
        sum += grid[row][col];
        sum += grid[row][col + 1];
        sum += grid[row][col + 2];
        sum += grid[row + 1][col + 1];
        sum += grid[row + 2][col];
        sum += grid[row + 2][col + 1];
        sum += grid[row + 2][col + 2];
        return sum;
    }
    int maxSum(vector<vector<int>> &grid)
    {
        int m{static_cast<int>(grid.size())};
        int n{static_cast<int>(grid[0].size())};
        int maxSum{}, sum{};
        for (int i{}; i <= m - 3; ++i)
        {
            for (int j{}; j <= n - 3; ++j)
            {
                sum = sumHourGlass(grid, i, j);
                if (maxSum < sum)
                    maxSum = sum;
            }
        }
        return maxSum;
    }
};