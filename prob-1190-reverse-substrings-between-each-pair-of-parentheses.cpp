#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string reverseParentheses(string s)
    {
        vector<char> stack;
        for (auto x : s)
        {
            if (x == '(')
                stack.push_back(x);
            else if (isalpha(x))
                stack.push_back(x);
            else if (x == ')')
            {
                string rev{};
                while (stack.back() != '(')
                {
                    rev += stack.back();
                    stack.pop_back();
                }
                stack.pop_back();
                for (auto y : rev)
                    stack.push_back(y);
            }
        }
        string ans{};
        for (auto x : stack)
            ans += x;
        return ans;
    }
};