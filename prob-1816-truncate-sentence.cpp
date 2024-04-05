#include <string>
using namespace std;

class Solution
{
public:
    string truncateSentence(string s, int k)
    {
        string trunc{};
        int words{};
        int i{};
        while (words < k)
        {
            if (i == static_cast<int>(s.size()))
                break;
            if (s[i] == ' ')
            {
                ++words;
                if (words != k)
                    trunc += s[i];
                ++i;
                continue;
            }
            trunc += s[i];
            ++i;
        }
        return trunc;
    }
};