#include <vector>
using namespace std;

class Solution
{
public:
    int oddCells(int m, int n, vector<vector<int>> &indices)
    {
        vector<vector<int>> matrix;
        for (int i{1}; i <= m; ++i)
        {
            vector<int> subMatrix;
            for (int j{1}; j <= n; ++j)
            {
                subMatrix.push_back(0);
            }
            matrix.push_back(subMatrix);
        }

        for (auto x : indices)
        {
            for (int col{}; col < n; ++col)
            {
                ++matrix[x[0]][col];
            }
            for (int row{}; row < m; ++row)
            {
                ++matrix[row][x[1]];
            }
        }

        int count{};

        for (int i{}; i < m; ++i)
        {
            for (int j{}; j < n; ++j)
            {
                if (matrix[i][j] % 2)
                    ++count;
            }
        }

        return count;
    }
};