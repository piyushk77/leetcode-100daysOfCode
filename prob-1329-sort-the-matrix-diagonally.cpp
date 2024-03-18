#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int m{static_cast<int>(mat.size())};
        int n{static_cast<int>(mat[0].size())};

        // diagonals from leftmost column
        for (int i{}; i < m; ++i)
        {
            vector<int> diagonal;
            for (int j{}, k{i}; j < n && k < m; ++j, ++k)
            {
                diagonal.push_back(mat[k][j]);
            }
            sort(diagonal.begin(), diagonal.end());
            for (int j{}, k{i}; j < n && k < m; ++j, ++k)
            {
                mat[k][j] = diagonal[j];
            }
        }

        // diagonals from topmost row
        for (int i{}; i < n; ++i)
        {
            vector<int> diagonal;
            for (int j{}, k{i}; j < m && k < n; ++j, ++k)
            {
                diagonal.push_back(mat[j][k]);
            }
            sort(diagonal.begin(), diagonal.end());
            for (int j{}, k{i}; j < m && k < n; ++j, ++k)
            {
                mat[j][k] = diagonal[j];
            }
        }

        return mat;
    }
};