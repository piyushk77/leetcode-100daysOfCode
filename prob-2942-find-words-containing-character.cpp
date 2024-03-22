#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<int> findWordsContaining(vector<string> &words, char x)
    {
        vector<int> ans;
        for (int i{}; i < words.size(); ++i)
        {
            for (auto letter : words[i])
                if (letter == x)
                {
                    ans.push_back(i);
                    break;
                }
        }
        return ans;
    }
};