#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int m{static_cast<int>(box.size())};
        int n{static_cast<int>(box[0].size())};
        for (int i{}; i < m; ++i)
        {
            for (int j{}; j < n; ++j)
            {
                int start{j};
                int stones{}, spaces{};
                while (j < n && box[i][j] != '*')
                {
                    if (box[i][j] == '#')
                        ++stones;
                    else
                        ++spaces;
                    ++j;
                }
                for (int k{start}; k < j; ++k)
                {
                    if (spaces)
                    {
                        box[i][k] = '.';
                        --spaces;
                    }
                    else
                    {
                        box[i][k] = '#';
                        --stones;
                    }
                }
            }
        }

        vector<vector<char>> verticalBox;
        for (int j{}; j < n; ++j)
        {
            vector<char> row;
            for (int i{m - 1}; i >= 0; --i)
            {
                row.push_back(box[i][j]);
            }
            verticalBox.push_back(row);
        }
        return verticalBox;
    }
};