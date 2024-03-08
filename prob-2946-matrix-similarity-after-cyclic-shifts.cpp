#include <vector>
using namespace std;

class Solution
{
public:
    inline vector<int> rightShift(vector<int> row, int k)
    {
        int n{static_cast<int>(row.size())};
        k %= n;
        vector<int> res;
        for (int i{n - k}; i < n; ++i)
            res.push_back(row[i]);
        for (int i{}; i < n - k; ++i)
            res.push_back(row[i]);
        return res;
    }

    inline vector<int> leftShift(vector<int> row, int k)
    {
        int n{static_cast<int>(row.size())};
        k %= n;
        vector<int> res;
        for (int i{k}; i < n; ++i)
            res.push_back(row[i]);
        for (int i{}; i < k; ++i)
            res.push_back(row[i]);
        return res;
    }

    inline bool areEqual(vector<vector<int>> matA, vector<vector<int>> matB)
    {
        int m{static_cast<int>(matA.size())};
        int n{static_cast<int>(matA[0].size())};
        for (int i{}; i < m; ++i)
        {
            for (int j{}; j < n; ++j)
                if (matA[i][j] != matB[i][j])
                    return false;
        }
        return true;
    }

    bool areSimilar(vector<vector<int>> &mat, int k)
    {
        vector<vector<int>> oldMat{mat};
        for (int i{}; i < mat.size(); ++i)
        {
            if (i % 2 == 0)
            {
                vector<int> shiftedRow{leftShift(mat[i], k)};
                mat[i] = shiftedRow;
            }
            else
            {
                vector<int> shiftedRow{rightShift(mat[i], k)};
                mat[i] = shiftedRow;
            }
        }
        return areEqual(oldMat, mat);
    }
};