#include <vector>
using namespace std;

class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int sum{};
        int n{static_cast<int>(mat.size())};
        for (int i{}, j{n - 1}; i < n; ++i, --j)
        {
            if (i != j)
                sum = mat[i][i] + mat[i][j] + sum;
            else
                sum += mat[i][i];
        }
        return sum;
    }
};