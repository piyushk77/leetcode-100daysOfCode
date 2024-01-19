#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int length{};
        for (int i{static_cast<int>(s.length() - 1)}; i >= 0; --i)
        {
            if (s[i] == ' ')
                continue;
            while (i >= 0 && s[i] != ' ')
            {
                ++length;
                --i;
            }
            break;
        }
        return length;
    }
};