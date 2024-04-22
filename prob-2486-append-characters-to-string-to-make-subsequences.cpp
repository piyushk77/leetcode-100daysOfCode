#include <string>
using namespace std;

class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        int lenT{static_cast<int>(t.size())};
        int lenS{static_cast<int>(s.size())};
        int cp{};
        int i{};
        for (; i < lenT; ++i)
        {
            bool found{false};
            for (; cp < lenS; ++cp)
            {
                if (s[cp] == t[i])
                {
                    found = true;
                    ++cp;
                    break;
                }
            }
            if (!found)
            {
                return (lenT - i);
            }
        }
        return (lenT - i);
    }
};