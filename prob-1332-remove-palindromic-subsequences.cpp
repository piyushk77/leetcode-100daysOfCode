#include <string>
using namespace std;

class Solution
{
public:
    int removePalindromeSub(string s)
    {
        string rev{};
        for (auto x : s)
            rev = x + rev;
        if (rev == s)
            return 1;
        return 2;
    }
};