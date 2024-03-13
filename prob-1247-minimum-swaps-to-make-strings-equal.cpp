#include <string>
using namespace std;

class Solution
{
public:
    int minimumSwap(string s1, string s2)
    {
        int straight{}, inverted{};
        int n{static_cast<int>(s1.length())};
        for (int i{}; i < n; ++i)
        {
            if (s1[i] != s2[i])
                if (s1[i] == 'x')
                    ++straight;
                else
                    ++inverted;
        }
        if ((straight + inverted) % 2 != 0)
            return -1;
        else if (inverted % 2)
        {
            --straight, --inverted;
            return (straight + inverted + 4) / 2;
        }
        else
            return (straight + inverted) / 2;
    }
};