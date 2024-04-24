#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        vector<string> stack;
        for (int i{}; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                string ch{"("};
                stack.push_back(ch);
            }
            if (s[i] == ')')
            {
                int score{};
                while (stack.back() != "(")
                {
                    score += stoi(stack.back());
                    stack.pop_back();
                }
                stack.pop_back();
                score = 2 * score;
                if (score == 0)
                    score = 1;
                stack.push_back(to_string(score));
            }
        }
        int score{};
        for (auto x : stack)
        {
            score += stoi(x);
        }
        return score;
    }
};