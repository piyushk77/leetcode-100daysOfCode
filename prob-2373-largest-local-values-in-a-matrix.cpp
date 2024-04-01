#include <vector>
using namespace std;

class Solution
{
public:
    int largestNum(vector<vector<int>> mat)
    {
        int max{};
        for (auto x : mat)
            for (auto y : x)
                if (max < y)
                    max = y;
        return max;
    }
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int n{static_cast<int>(grid.size())};
        vector<vector<int>> answer;
        for (int i{}; i < n - 2; ++i)
        {
            vector<int> ans;
            for (int j{}; j < n - 2; ++j)
            {
                vector<vector<int>> mat{
                    {grid[i][j], grid[i][j + 1], grid[i][j + 2]},
                    {grid[i + 1][j], grid[i + 1][j + 1], grid[i + 1][j + 2]},
                    {grid[i + 2][j], grid[i + 2][j + 1], grid[i + 2][j + 2]}};
                ans.push_back(largestNum(mat));
            }
            answer.push_back(ans);
        }
        return answer;
    }
};