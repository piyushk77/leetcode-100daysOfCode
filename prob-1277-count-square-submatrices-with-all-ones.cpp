#include <vector>
using namespace std;

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int m{static_cast<int>(matrix.size())};
        int n{static_cast<int>(matrix[0].size())};
        int sideMax{min(m, n)};
        int count{};
        for (int side{1}; side <= sideMax; ++side)
        {
            for (int row{}; row < m - side + 1; ++row)
            {
                for (int col{}; col < n - side + 1; ++col)
                {
                    bool flag{true};
                    for (int i{row}; i < row + side; ++i)
                    {
                        for (int j{col}; j < col + side; ++j)
                        {
                            if (matrix[i][j] != 1)
                            {
                                flag = false;
                                break;
                            }
                        }
                        if (!flag)
                            break;
                    }
                    if (flag)
                        ++count;
                }
            }
        }
        return count;
    }
};