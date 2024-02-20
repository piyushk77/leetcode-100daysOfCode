#include <vector>
#include <cmath>
using namespace std;
class Solution
{
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter,
                                          int cCenter)
    {
        vector<vector<vector<int>>> segregate;

        int leftTopDiagonal{abs(0 - rCenter) + abs(0 - cCenter)};
        int rightBottomDiagonal{abs(rows - 1 - rCenter) +
                                abs(cols - 1 - cCenter)};

        int leftBottomDiagonal{abs(rows - 1 - rCenter) + abs(0 - cCenter)};
        int rightTopDiagonal{abs(0 - rCenter) + abs(cols - 1 - cCenter)};

        int max1{max(leftTopDiagonal, rightBottomDiagonal)};
        int max2{max(leftBottomDiagonal, rightTopDiagonal)};

        int maxDistance{max(max1, max2)};

        for (int i{}; i <= maxDistance; ++i)
        {
            segregate.push_back({{-1, -1}});
        }

        for (int i{}; i < rows; ++i)
        {
            for (int j{}; j < cols; ++j)
            {
                int distance{abs(i - rCenter) + abs(j - cCenter)};
                segregate[distance].push_back({i, j});
            }
        }
        vector<vector<int>> res;
        for (auto x : segregate)
        {
            for (int i{1}; i < x.size(); ++i)
            {
                res.push_back(x[i]);
            }
        }
        return res;
    }
};