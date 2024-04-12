#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        vector<char> stack;
        int count{};
        for (auto x : s)
        {
            if (x == '(')
                stack.push_back(x);
            else if (stack.size())
            {
                stack.pop_back();
            }
            else
                ++count;
        }
        count += stack.size();
        return count;
    }
};