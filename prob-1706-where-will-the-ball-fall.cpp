#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findBall(vector<vector<int>> &grid)
    {
        int n{static_cast<int>(grid[0].size())};
        int m{static_cast<int>(grid.size())};
        vector<int> answer;
        for (int col{}; col < n; ++col)
        {
            int i{}, j{col};
            bool pass{true};
            int inc{grid[i][j]};
            while (i < m && j < n && i >= 0 && j >= 0)
            {
                inc = grid[i][j];
                if (j + inc < n && j + inc >= 0)
                {
                    if (grid[i][j] == grid[i][j + inc])
                    {
                        ++i;
                        j += inc;
                    }
                    else
                    {
                        pass = false;
                        break;
                    }
                }
                else
                {
                    pass = false;
                    break;
                }
            }
            if (pass)
            {
                answer.push_back(j);
            }
            else
                answer.push_back(-1);
        }
        return answer;
    }
};