#include <string>
using namespace std;

class Solution
{
public:
    bool isOddDigit(char ch)
    {
        if (ch == '1' || ch == '3' || ch == '5' || ch == '7' || ch == '9')
            return true;
        return false;
    }
    string largestOddNumber(string num)
    {
        for (int i{static_cast<int>(num.size()) - 1}; i >= 0; --i)
        {
            if (isOddDigit(num[i]))
            {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};