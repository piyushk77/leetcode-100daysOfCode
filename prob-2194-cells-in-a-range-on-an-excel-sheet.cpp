#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> cellsInRange(string s)
    {
        vector<string> ans;
        char col1{s[0]};
        string row1str{s[1]};
        int row1{stoi(row1str)};

        char col2{s[3]};
        string row2str{s[4]};
        int row2{stoi(row2str)};

        for (char i{col1}; i <= col2; ++i)
        {
            for (int j{row1}; j <= row2; ++j)
            {
                string cell{};
                cell = i + to_string(j);
                ans.push_back(cell);
            }
        }
        return ans;
    }
};