#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string prefix{};
        int i{};
        while (true)
        {
            if (i == strs[0].length())
            {
                break;
            }
            char commonChar{strs[0][i]};
            bool flag{true};
            for (auto str : strs)
            {
                if (i < str.length())
                {
                    if (str[i] != commonChar)
                    {
                        flag = false;
                        break;
                    }
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
            prefix += commonChar;
            ++i;
        }
        return prefix;
    }
};