#include <vector>
using namespace std;

class Solution
{
public:
    int sumMat(int i, int j, int x, int y, vector<vector<int>> &mat)
    {
        if (i < 0)
            i = 0;
        if (j < 0)
            j = 0;
        if (x >= mat.size())
            x = static_cast<int>(mat.size()) - 1;
        if (y >= mat[0].size())
            y = static_cast<int>(mat[0].size()) - 1;
        int sum{};
        for (int row{i}; row <= x; ++row)
        {
            for (int col{j}; col <= y; ++col)
            {
                sum += mat[row][col];
            }
        }
        return sum;
    }

    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k)
    {
        vector<vector<int>> answer;
        for (int i{}; i < mat.size(); ++i)
        {
            vector<int> row;
            for (int j{}; j < mat[0].size(); ++j)
            {
                row.push_back(sumMat(i - k, j - k, i + k, j + k, mat));
            }
            answer.push_back(row);
        }
        return answer;
    }
};