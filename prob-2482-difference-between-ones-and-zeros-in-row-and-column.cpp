#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        vector<int> onesRowMat, onesColMat, zerosRowMat, zerosColMat;
        int m{static_cast<int>(grid.size())};
        int n{static_cast<int>(grid[0].size())};
        for (int i{}; i < m; ++i)
        {
            int ones{}, zeros{};
            for (int j{}; j < n; ++j)
            {
                if (grid[i][j] == 1)
                    ++ones;
                else
                    ++zeros;
            }
            onesRowMat.push_back(ones);
            zerosRowMat.push_back(zeros);
        }

        for (int i{}; i < n; ++i)
        {
            int ones{}, zeros{};
            for (int j{}; j < m; ++j)
            {
                if (grid[j][i] == 1)
                    ++ones;
                else
                    ++zeros;
            }
            onesColMat.push_back(ones);
            zerosColMat.push_back(zeros);
        }

        vector<vector<int>> res;
        for (int i{}; i < m; ++i)
        {
            vector<int> diff;
            for (int j{}; j < n; ++j)
            {
                int difference{onesRowMat[i] + onesColMat[j] - zerosRowMat[i] -
                               zerosColMat[j]};
                diff.push_back(difference);
            }
            res.push_back(diff);
        }

        return res;
    }
};