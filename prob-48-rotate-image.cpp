#include <vector>
using namespace std;
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        for (int i{}; i < matrix.size() / 2; ++i)
        {
            vector<int> temp{matrix[i]};
            matrix[i] = matrix[matrix.size() - i - 1];
            matrix[matrix.size() - i - 1] = temp;
        }

        for (int i{}; i < matrix.size(); ++i)
        {
            for (int j{i + 1}; j < matrix.size(); ++j)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
};