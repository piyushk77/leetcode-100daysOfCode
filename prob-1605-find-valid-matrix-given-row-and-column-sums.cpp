#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum,
                                      vector<int> &colSum)
    {
        int m{static_cast<int>(rowSum.size())};
        int n{static_cast<int>(colSum.size())};
        vector<vector<int>> res(m, vector<int>(n));
        for (int row{}; row < m; ++row)
        {
            for (int col{}; col < n; ++col)
            {
                res[row][col] = min(rowSum[row], colSum[col]);
                rowSum[row] -= res[row][col];
                colSum[col] -= res[row][col];
            }
        }
        return res;
    }
};