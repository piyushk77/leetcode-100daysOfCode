#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int returnType(char ch)
    {
        switch (ch)
        {
        case '{':
            return 1;
        case '[':
            return 2;
        case '(':
            return 3;
        case '}':
            return 1;
        case ']':
            return 2;
        case ')':
            return 3;
        default:
            return 0;
        }
        return -1;
    }
    int isBracket(char ch)
    {
        switch (ch)
        {
        case '{':
        case '[':
        case '(':
            return 1;
        case '}':
        case ']':
        case ')':
            return 2;
        default:
            return 0;
        }
        return -1;
    }
    bool isValid(string s)
    {
        vector<char> brackets;
        for (int i{}; i < s.length(); ++i)
        {
            if (!isBracket(s[i]))
                continue;
            if (isBracket(s[i]) == 1)
            {
                brackets.push_back(s[i]);
            }
            else if (isBracket(s[i]) == 2)
            {
                if (!brackets.size())
                    return false;
                char ch{brackets.back()};
                if (returnType(s[i]) == returnType(ch))
                    brackets.pop_back();
                else
                    return false;
            }
        }
        if (!brackets.size())
            return true;
        return false;
    }
};