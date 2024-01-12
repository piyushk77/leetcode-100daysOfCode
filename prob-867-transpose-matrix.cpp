#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        int m{static_cast<int>(matrix.size())};
        int n{static_cast<int>(matrix[0].size())};

        vector<vector<int>> transpose(n, vector<int>(m, 0));

        for (int i{}; i < m; ++i)
        {
            for (int j{}; j < n; ++j)
            {
                transpose[j][i] = matrix[i][j];
            }
        }

        return transpose;
    }
};