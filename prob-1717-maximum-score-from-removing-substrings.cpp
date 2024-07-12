#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        stack<char> mainStack;
        int abCount{}, baCount{};
        for (auto ch : s)
            if (ch != 'b' || mainStack.empty())
                mainStack.push(ch);
            else if (mainStack.top() == 'a')
            {
                mainStack.pop();
                ++abCount;
            }
            else
                mainStack.push(ch);
        stack<char> buffer;
        while (!mainStack.empty())
        {
            char top{mainStack.top()};
            mainStack.pop();
            if (top != 'b' || buffer.empty())
                buffer.push(top);
            else if (buffer.top() == 'a')
            {
                buffer.pop();
                ++baCount;
            }
            else
                buffer.push(top);
        }

        mainStack = buffer = stack<char>();
        int pointsAB{x * abCount + y * baCount};
        abCount = baCount = 0;

        for (auto ch : s)
        {
            if (ch != 'a' || mainStack.empty())
                mainStack.push(ch);
            else if (mainStack.top() == 'b')
            {
                mainStack.pop();
                ++baCount;
            }
            else
                mainStack.push(ch);
        }
        while (!mainStack.empty())
        {
            char top{mainStack.top()};
            mainStack.pop();
            if (top != 'a' || buffer.empty())
                buffer.push(top);
            else if (buffer.top() == 'b')
            {
                buffer.pop();
                ++abCount;
            }
            else
                buffer.push(top);
        }
        int pointsBA{x * abCount + y * baCount};
        if (pointsAB > pointsBA)
            return pointsAB;
        return pointsBA;
    }
};