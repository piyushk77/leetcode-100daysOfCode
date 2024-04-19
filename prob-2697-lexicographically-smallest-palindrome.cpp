#include <string>
using namespace std;

class Solution
{
public:
    string makeSmallestPalindrome(string s)
    {
        int len{static_cast<int>(s.size())};
        for (int i{}; i < len / 2; ++i)
            if (s[i] != s[len - i - 1])
            {
                char minCh{min(s[i], s[len - i - 1])};
                s[i] = s[len - i - 1] = minCh;
            }
        return s;
    }
};