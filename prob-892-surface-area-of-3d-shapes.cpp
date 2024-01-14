#include <vector>
using namespace std;
class Solution
{
public:
    int surfaceArea(vector<vector<int>> &grid)
    {
        int n{static_cast<int>(grid.size())};
        int totalArea{};
        for (int i{}; i < n; ++i)
        {
            for (int j{}; j < n; ++j)
            {
                int westArea{}, northArea{}, eastArea{}, southArea{}, topArea{}, bottomArea{};
                // check west neighbour existence
                if (j - 1 >= 0)
                {
                    westArea = grid[i][j] - grid[i][j - 1];
                    if (westArea < 0)
                        westArea = 0;
                }
                else
                {
                    westArea = grid[i][j];
                }

                // check north neighbour existence
                if (i - 1 >= 0)
                {
                    northArea = grid[i][j] - grid[i - 1][j];
                    if (northArea < 0)
                        northArea = 0;
                }
                else
                {
                    northArea = grid[i][j];
                }

                // check east neighbour existence
                if (j + 1 < n)
                {
                    eastArea = grid[i][j] - grid[i][j + 1];
                    if (eastArea < 0)
                        eastArea = 0;
                }
                else
                {
                    eastArea = grid[i][j];
                }

                // check south neighbour existence
                if (i + 1 < n)
                {
                    southArea = grid[i][j] - grid[i + 1][j];
                    if (southArea < 0)
                        southArea = 0;
                }
                else
                {
                    southArea = grid[i][j];
                }
                if (grid[i][j])
                {
                    topArea = bottomArea = 1;
                }
                int elementArea{westArea + northArea + eastArea + southArea + topArea + bottomArea};
                totalArea += elementArea;
            }
        }
        return totalArea;
    }
};