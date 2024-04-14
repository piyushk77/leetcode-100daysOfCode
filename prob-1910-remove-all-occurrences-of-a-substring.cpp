#include <string>
using namespace std;

class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        int len{static_cast<int>(part.size())};
        int totalLen{static_cast<int>(s.size())};
        for (int i{}; i < (static_cast<int>(s.size()) - len + 1); ++i)
        {
            string sub{s.substr(i, len)};
            if (sub == part)
            {
                s.erase(i, len);
                i -= len + 1;
                if (i < -1)
                    i = -1;
            }
        }
        return s;
    }
};