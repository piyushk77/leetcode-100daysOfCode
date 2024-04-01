#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool isAcronym(vector<string> &words, string s)
    {
        if (s.size() != words.size())
            return false;
        for (int i{}; i < words.size(); ++i)
        {
            if (words[i][0] != s[i])
                return false;
        }
        return true;
    }
};