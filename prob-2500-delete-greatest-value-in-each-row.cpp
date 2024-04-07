#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int deleteGreatestValue(vector<vector<int>> &grid)
    {
        for (int i{}; i < grid.size(); ++i)
        {
            sort(grid[i].begin(), grid[i].end(), greater<int>());
        }

        int answer{};
        for (int i{}; i < grid[0].size(); ++i)
        {
            int max{};
            for (int j{}; j < grid.size(); ++j)
                if (max < grid[j][i])
                    max = grid[j][i];
            answer += max;
        }

        return answer;
    }
};