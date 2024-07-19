#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int n{static_cast<int>(matrix.size())};
        int m{static_cast<int>(matrix[0].size())};
        for (int i{}; i < n; ++i)
        {
            for (int j{}; j < m; ++j)
            {
                int rowMin{matrix[i][j]};
                int colMax{matrix[i][j]};
                for (int row{}; row < n; ++row)
                {
                    if (colMax < matrix[row][j])
                        colMax = matrix[row][j];
                }
                for (int col{}; col < m; ++col)
                {
                    if (rowMin > matrix[i][col])
                        rowMin = matrix[i][col];
                }
                if (rowMin == colMax)
                    ans.push_back(matrix[i][j]);
            }
        }
        return ans;
    }
};