#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution
{
public:
    string incrementBracket(string str)
    {
        char carry{')'};
        for (int i{static_cast<int>(str.size() - 1)}; i >= 0; --i)
        {
            if (str[i] == '(')
            {
                str[i] = carry;
                return str;
            }
            else
            {
                str[i] = '(';
                continue;
            }
        }
        return str;
    }
    bool isValidParentheses(string str)
    {
        vector<char> stackBracket;
        for (int i{}; i < str.size(); ++i)
        {
            if (str[i] == '(')
                stackBracket.push_back('(');
            else if (str[i] == ')')
            {
                if (stackBracket.size() != 0)
                {
                    stackBracket.pop_back();
                }
                else
                    return false;
            }
        }
        if (stackBracket.size())
            return false;
        return true;
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        string str{""};
        for (int i{1}; i <= 2 * n; ++i)
        {
            str += "(";
        }
        for (int i{1}; i <= pow(2, 2 * n); ++i)
        {
            if (isValidParentheses(str))
                result.push_back(str);
            str = incrementBracket(str);
        }
        return result;
    }
};