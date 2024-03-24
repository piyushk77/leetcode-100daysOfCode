#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int moves(int n, vector<int> startPos, string s, int index)
    {
        int count{};
        int row{startPos[0]};
        int col{startPos[1]};
        for (int i{index}; i < s.size(); ++i)
        {
            switch (s[i])
            {
            case 'R':
            {
                if ((col + 1) < n)
                {
                    ++count;
                    ++col;
                }
                else
                    return count;
            }
            break;
            case 'L':
            {
                if ((col - 1) >= 0)
                {
                    ++count;
                    --col;
                }
                else
                    return count;
            }
            break;
            case 'U':
            {
                if ((row - 1) >= 0)
                {
                    ++count;
                    --row;
                }
                else
                    return count;
            }
            break;
            case 'D':
            {
                if ((row + 1) < n)
                {
                    ++count;
                    ++row;
                }
                else
                    return count;
            }
            break;
            default:
                return -1;
            }
        }
        return count;
    }

    vector<int> executeInstructions(int n, vector<int> &startPos, string s)
    {
        vector<int> ans;
        for (int i{}; i < s.size(); ++i)
        {
            ans.push_back(moves(n, startPos, s, i));
        }
        return ans;
    }
};