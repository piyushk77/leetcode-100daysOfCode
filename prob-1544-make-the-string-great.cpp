#include <string>
#include <cctype>
using namespace std;

class Solution
{
public:
    bool stringIsGood(string s)
    {
        for (int i{}; i < (static_cast<int>(s.size()) - 1); ++i)
        {
            if (tolower(s[i]) == tolower(s[i + 1]))
            {
                if ((islower(s[i]) && isupper(s[i + 1])) || (islower(s[i + 1]) && isupper(s[i])))
                {
                    return false;
                }
            }
        }
        return true;
    }
    string makeGood(string s)
    {
        while (!stringIsGood(s))
        {
            string newStr{};
            int i{};
            for (; i < (static_cast<int>(s.size()) - 1); ++i)
            {
                if (tolower(s[i]) == tolower(s[i + 1]))
                {
                    if ((islower(s[i]) && isupper(s[i + 1])) || (islower(s[i + 1]) && isupper(s[i])))
                    {
                        i += 2;
                        break;
                    }
                    else
                        newStr += s[i];
                }
                else
                    newStr += s[i];
            }
            while (i < s.size())
            {
                newStr += s[i];
                ++i;
            }
            s = newStr;
        }
        return s;
    }
};