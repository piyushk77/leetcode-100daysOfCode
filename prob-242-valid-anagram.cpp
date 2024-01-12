#include <string>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int flag{};
        if (s.length() != t.length())
            return false;

        for (int i{}; i < s.length(); ++i)
        {
            for (int j{}; j < t.length(); ++j)
            {
                if (t[j] == s[i])
                {
                    flag = 1;
                    t.erase(t.begin() + j);
                    break;
                }
            }
            if (!flag)
                return false;
            else
                flag = 0;
        }
        return true;
    }
};