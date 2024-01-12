#include <string>
#include <cctype>
using namespace std;
class Solution
{
public:
    bool isVowel(char ch)
    {
        ch = tolower(ch);
        switch (ch)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
        }
        return false;
    }
    bool halvesAreAlike(string s)
    {
        string a{s.substr(0, s.length() / 2)};
        string b{s.substr(s.length() / 2, s.length())};

        int aCount{}, bCount{};

        for (int i{}; i < a.length(); ++i)
        {
            if (isVowel(a[i]))
            {
                ++aCount;
            }
            if (isVowel(b[i]))
            {
                ++bCount;
            }
        }

        if (aCount == bCount)
            return true;
        return false;
    }
};