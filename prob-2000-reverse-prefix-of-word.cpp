#include <string>
using namespace std;

class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        string rev{};
        int i{};
        for (; i < word.size(); ++i)
        {
            if (word[i] == ch)
            {
                rev = ch + rev;
                break;
            }
            rev = word[i] + rev;
        }
        if (i >= word.size())
            return word;
        ++i;
        for (; i < word.size(); ++i)
            rev += word[i];
        return rev;
    }
};