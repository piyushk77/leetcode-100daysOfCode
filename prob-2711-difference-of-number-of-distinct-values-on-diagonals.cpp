#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>> &grid)
    {
        const int SIZE{50};
        vector<vector<int>> answer;
        int n{static_cast<int>(grid.size())};
        int m{static_cast<int>(grid[0].size())};
        for (int i{}; i < n; ++i)
        {
            vector<int> ansRow;
            for (int j{}; j < m; ++j)
            {
                int row{i - 1}, col{j - 1};
                // traverse the top-diagonal
                vector<int> hashTop(SIZE + 1, 0);
                while (row >= 0 && col >= 0)
                {
                    ++hashTop[grid[row][col]];
                    --row, --col;
                }
                row = i + 1;
                col = j + 1;
                // traverse the down-diagonal
                vector<int> hashDown(SIZE + 1, 0);
                while (row < n && col < m)
                {
                    ++hashDown[grid[row][col]];
                    ++row, ++col;
                }

                int topLeft{}, bottomRight{};
                for (int i{}; i <= SIZE; ++i)
                {
                    if (hashTop[i])
                        ++topLeft;
                    if (hashDown[i])
                        ++bottomRight;
                }

                ansRow.push_back(abs(topLeft - bottomRight));
            }
            answer.push_back(ansRow);
        }
        return answer;
    }
};