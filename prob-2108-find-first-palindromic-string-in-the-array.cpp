#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int len{static_cast<int>(s.size())};
        for (int i{}, j{len - 1}; i <= len / 2; ++i, --j)
            if (s[i] != s[j])
                return false;
        return true;
    }
    string firstPalindrome(vector<string> &words)
    {
        for (auto s : words)
        {
            if (isPalindrome(s))
                return s;
        }
        return "";
    }
};