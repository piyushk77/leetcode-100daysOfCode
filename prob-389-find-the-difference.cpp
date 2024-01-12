#include <string>
using namespace std;
class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        char ch{};
        int flag{};
        for (int i{}; i < t.length(); ++i)
        {
            for (int j{}; j < s.length(); ++j)
            {
                if (s[j] == t[i])
                {
                    s.erase(s.begin() + j);
                    flag = 1;
                    break;
                }
            }
            if (!flag)
            {
                ch = t[i];
                return ch;
            }
            else
                flag = 0;
        }
        return ch;
    }
};