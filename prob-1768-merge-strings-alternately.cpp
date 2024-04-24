#include <string>
using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int i{};
        string str{}, smallWord{}, largeWord{};
        if (word1.size() < word2.size())
            smallWord = word1, largeWord = word2;
        else
            smallWord = word2, largeWord = word1;
        for (; i < smallWord.size(); ++i)
            str = str + word1[i] + word2[i];
        for (; i < largeWord.size(); ++i)
            str = str + largeWord[i];
        return str;
    }
};