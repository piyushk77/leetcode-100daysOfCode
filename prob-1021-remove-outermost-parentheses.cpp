#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        vector<char> stack;
        string ans{};
        int left{}, right{};
        for (auto x : s)
        {
            if (x == '(')
            {
                stack.push_back(x);
                ++left;
            }
            else
            {
                ++right;
                int len{static_cast<int>(stack.size()) + 1};
                if (left == right)
                {
                    for (int i{1}; i < len - 1; ++i)
                    {
                        if (stack[1] == ')')
                            break;
                        ans += stack[i];
                    }
                    stack.clear();
                    left = right = 0;
                }
                else
                    stack.push_back(x);
            }
        }
        return ans;
    }
};