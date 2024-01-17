#include <string>
using namespace std;

class Solution
{
public:
    int unitToInt(string unit)
    {
        switch (unit[0])
        {
        case 'I':
            return 1 * unit.length();
        case 'V':
            return 5 * unit.length();
        case 'X':
            return 10 * unit.length();
        case 'L':
            return 50 * unit.length();
        case 'C':
            return 100 * unit.length();
        case 'D':
            return 500 * unit.length();
        case 'M':
            return 1000 * unit.length();
        }
        return 0;
    }

    int romanToInt(string s)
    {
        int num{};
        for (int i{}; i < s.length(); ++i)
        {
            char ch{s[i]};
            string unit{};
            if (i + 1 < s.length() && ch == s[i + 1])
            {
                unit += ch;
                ++i;
                while (i < s.length() && ch == s[i])
                {
                    unit += ch;
                    ++i;
                }
                num += unitToInt(unit);
                --i;
                continue;
            }
            if (i + 1 < s.length())
            {
                switch (ch)
                {
                case 'I':
                {
                    if (s[i + 1] == 'V')
                    {
                        num += 4;
                        ++i;
                        continue;
                    }
                    else if (s[i + 1] == 'X')
                    {
                        num += 9;
                        ++i;
                        continue;
                    }
                    else
                    {
                        unit += ch;
                        num += unitToInt(unit);
                        continue;
                    }
                }
                case 'X':
                {
                    if (s[i + 1] == 'L')
                    {
                        num += 40;
                        ++i;
                        continue;
                    }
                    else if (s[i + 1] == 'C')
                    {
                        num += 90;
                        ++i;
                        continue;
                    }
                    else
                    {
                        unit += ch;
                        num += unitToInt(unit);
                        continue;
                    }
                }
                case 'C':
                {
                    if (s[i + 1] == 'D')
                    {
                        num += 400;
                        ++i;
                        continue;
                    }
                    else if (s[i + 1] == 'M')
                    {
                        num += 900;
                        ++i;
                        continue;
                    }
                    else
                    {
                        unit += ch;
                        num += unitToInt(unit);
                        continue;
                    }
                }
                case 'V':
                case 'L':
                case 'D':
                case 'M':
                {
                    unit += ch;
                    num += unitToInt(unit);
                    break;
                }
                default:
                    return -1;
                }
            }
            else
            {
                unit += ch;
                num += unitToInt(unit);
            }
        }
        return num;
    }
};