#include <string>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (haystack.length() < needle.length())
            return -1;
        for (int i{}; i < (haystack.length() - needle.length() + 1); ++i)
        {
            int isPresent{true};
            for (int k{i}, j{}; j < needle.length(); ++k, ++j)
            {
                if (haystack[k] != needle[j])
                {
                    isPresent = false;
                    break;
                }
            }
            if (isPresent)
                return i;
        }

        return -1;
    }
};