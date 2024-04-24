#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string removeTrail(string str)
    {
        string newStr{};
        int i{static_cast<int>(str.size()) - 1};
        for (; i >= 0; --i)
        {
            if (str[i] != ' ')
                break;
        }
        for (; i >= 0; --i)
            newStr = str[i] + newStr;
        return newStr;
    }
    vector<string> printVertically(string s)
    {
        vector<string> words{};
        int maxLen{};
        {
            string word{};
            for (auto x : s)
            {
                if (x == ' ')
                {
                    words.push_back(word);
                    if (maxLen < word.size())
                        maxLen = word.size();
                    word.clear();
                }
                else
                {
                    word += x;
                }
            }
            if (maxLen < word.size())
                maxLen = word.size();
            words.push_back(word);
        }

        vector<string> verticals;
        for (int col{}; col < maxLen; ++col)
        {
            string vert{};
            for (int i{}; i < words.size(); ++i)
            {
                if (!isalpha(words[i][col]))
                {
                    vert += ' ';
                }
                else
                {
                    vert += words[i][col];
                }
            }
            vert = removeTrail(vert);
            verticals.push_back(vert);
        }

        return verticals;
    }
};