#include <string>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int len{static_cast<int>(s.size())};
        for (int i{len - 1}, j{}; i >= len / 2; --i, ++j)
        {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
    int countSubstrings(string s)
    {
        int count{};
        for (int window{1}; window <= static_cast<int>(s.size()); ++window)
        {
            for (int i{}; i <= static_cast<int>(s.size() - window); ++i)
            {
                string x{s.substr(i, window)};
                if (isPalindrome(x))
                {
                    ++count;
                }
            }
        }
        return count;
    }
};