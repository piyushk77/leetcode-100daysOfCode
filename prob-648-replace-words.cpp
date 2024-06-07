#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        unordered_set<string> hash;
        for (auto x : dictionary)
            hash.insert(x);
        string newSentence{};
        int n{static_cast<int>(sentence.size())};
        int i{};
        while (i < n)
        {
            string word{};
            while (i < n && sentence[i] != ' ')
                word += sentence[i++];
            string root{};
            for (auto x : word)
            {
                if (hash.find(root + x) != hash.end())
                {
                    root += x;
                    break;
                }
                else
                    root += x;
            }
            newSentence += " " + root;
            ++i;
        }
        newSentence.erase(0, 1);
        return newSentence;
    }
};