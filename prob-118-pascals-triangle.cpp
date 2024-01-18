#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> pascal{{1}, {1, 1}};
        if (numRows == 1)
            return {{1}};
        if (numRows == 2)
            return pascal;
        for (int i{3}; i <= numRows; ++i)
        {
            vector<int> lastRow{pascal.back()};
            vector<int> currentRow{1};
            for (int j{}; j < lastRow.size() - 1; ++j)
            {
                currentRow.push_back(lastRow[j] + lastRow[j + 1]);
            }
            currentRow.push_back(1);
            pascal.push_back(currentRow);
        }
        return pascal;
    }
};