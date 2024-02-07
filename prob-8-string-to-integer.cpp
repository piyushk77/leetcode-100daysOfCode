#include <string>
#include <cmath>
using namespace std;

class Solution
{
public:
    int chToNum(char ch)
    {
        switch (ch)
        {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            return -1;
        }
    }
    int myAtoi(string s)
    {
        while (s[0] == ' ')
            s.erase(s.begin() + 0);

        if (!s.size())
            return 0;

        int sign{1};
        if (s.size() > 1)
        {
            if (s[0] == '-')
            {
                sign = -1;
                s.erase(s.begin() + 0);
            }
            else if (s[0] == '+')
            {
                sign = 1;
                s.erase(s.begin() + 0);
            }
        }

        string newStr{};
        for (int j{}; j < s.size(); ++j)
        {
            if (!isdigit(s[j]))
                break;
            else
            {
                newStr += s[j];
            }
        }

        long long num{};
        for (int k{}; k < newStr.size(); ++k)
        {
            int digit{chToNum(newStr[k])};
            num = num * 10 + digit;
            if (num >= pow(2, 31))
            {
                if (sign == -1)
                {
                    return sign * pow(2, 31);
                }
                else
                    return pow(2, 31) - 1;
            }
        }

        return sign * num;
    }
};