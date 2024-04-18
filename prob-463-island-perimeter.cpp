#include <vector>
using namespace std;

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int m{static_cast<int>(grid.size())};
        int n{static_cast<int>(grid[0].size())};
        int perimeter{};
        for (int row{}; row < m; ++row)
        {
            for (int col{}; col < n; ++col)
            {
                if (grid[row][col])
                {
                    perimeter += 2;
                    while (col < n && grid[row][col])
                    {
                        if (row - 1 >= 0)
                        {
                            if (grid[row - 1][col] == 0)
                            {
                                ++perimeter;
                            }
                            if (row + 1 < m)
                            {
                                if (grid[row + 1][col] == 0)
                                    ++perimeter;
                            }
                            else
                            {
                                ++perimeter;
                            }
                        }
                        else
                        {
                            ++perimeter;
                            if (row + 1 < m)
                            {
                                if (grid[row + 1][col] == 0)
                                    ++perimeter;
                            }
                            else
                            {
                                ++perimeter;
                            }
                        }
                        ++col;
                    }
                    --col;
                }
            }
        }
        return perimeter;
    }
};