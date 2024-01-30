#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int evaluate(int op1, int op2, string op)
    {
        switch (op[0])
        {
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            return op1 / op2;
        default:
            return 0;
        }
        return 0;
    }

    bool isop(string op)
    {
        if (op == "+" || op == "-" || op == "*" || op == "/")
        {
            return true;
        }
        return false;
    }

    int evalRPN(vector<string> &tokens)
    {
        vector<int> result;
        for (auto x : tokens)
        {
            if (isop(x))
            {
                int secondOp{result.back()};
                result.pop_back();
                int firstOp{result.back()};
                result.pop_back();
                result.push_back(evaluate(firstOp, secondOp, x));
            }
            else
            {
                result.push_back(stoi(x));
            }
        }
        return result[0];
    }
};