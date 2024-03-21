#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words,
                                         string pattern)
    {
        vector<string> res;
        for (auto word : words)
        {
            if (word.size() != pattern.size())
                continue;
            vector<int> mappings(static_cast<int>('z'), -1);
            vector<int> mappings2(static_cast<int>('z'), -1);
            for (int i{}; i < word.size(); ++i)
            {
                if (mappings[static_cast<int>(word[i]) - 1] == -1 &&
                    mappings2[static_cast<int>(pattern[i]) - 1] == -1)
                {
                    mappings[static_cast<int>(word[i]) - 1] =
                        static_cast<int>(pattern[i]) - 1;
                    mappings2[static_cast<int>(pattern[i]) - 1] =
                        static_cast<int>(word[i]) - 1;
                }
            }
            string recreate{};
            for (int i{}; i < word.size(); ++i)
            {
                char patLetter{static_cast<char>(
                    mappings[static_cast<int>(word[i]) - 1] + 1)};
                recreate += patLetter;
            }
            if (recreate == pattern)
                res.push_back(word);
        }
        return res;
    }
};