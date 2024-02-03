#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        bool stateReversed{false};
        vector<string> zigzag;
        for (int i{1}; i <= numRows; ++i)
            zigzag.push_back("");

        for (int i{}, j{}; i < s.size(); ++i)
        {
            if (!stateReversed)
            {
                zigzag[j] += s[i];
                if (j == numRows - 1)
                {
                    stateReversed = true;
                    --j;
                }
                else
                {
                    ++j;
                }
            }
            else
            {
                zigzag[j] += s[i];
                if (j == 0)
                {
                    stateReversed = false;
                    ++j;
                }
                else
                {
                    --j;
                }
            }
        }

        string result{};
        for (auto x : zigzag)
        {
            result += x;
        }
        return result;
    }
};