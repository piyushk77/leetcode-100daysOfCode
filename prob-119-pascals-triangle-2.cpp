#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> firstRow{1};
        vector<int> secondRow{1, 1};
        vector<vector<int>> pascalsTriangle{firstRow, secondRow};
        if (rowIndex == 0)
            return firstRow;
        if (rowIndex == 1)
            return secondRow;
        for (int i{2}; i <= rowIndex; ++i)
        {
            vector<int> previousRow{pascalsTriangle.back()};
            vector<int> currentRow;
            currentRow.push_back(1);
            for (int x{}; x < previousRow.size() - 1; ++x)
            {
                currentRow.push_back(previousRow[x] + previousRow[x + 1]);
            }
            currentRow.push_back(1);
            pascalsTriangle.push_back(currentRow);
        }
        return pascalsTriangle.back();
    }
};