#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string revStr(string txt)
    {
        string rev{};
        for (int i{static_cast<int>(txt.size()) - 1}; i >= 0; --i)
            rev += txt[i];
        return rev;
    }
    int maximumNumberOfStringPairs(vector<string> &words)
    {
        vector<string> revWords;
        for (auto x : words)
        {
            revWords.push_back(revStr(x));
        }
        int count{};
        for (int i{}; i < words.size(); ++i)
        {
            for (int j{i + 1}; j < revWords.size(); ++j)
            {
                if (words[i] == revWords[j])
                    ++count;
            }
        }
        return count;
    }
};