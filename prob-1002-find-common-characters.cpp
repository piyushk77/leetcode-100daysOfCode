#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        vector<unordered_map<char, int>> hashWord;
        // Store all the characters in their respective hash
        for (auto word : words)
        {
            unordered_map<char, int> hash;
            for (auto ch : word)
                hash[ch]++;
            hashWord.push_back(hash);
        }

        // Store the characters of the first word
        string firstWord{words[0]};

        // Check the presence of each of these characters in every other word
        vector<string> res;
        for (auto x : firstWord)
        {
            bool flag{true};
            for (auto &hash : hashWord)
            {
                if (hash.find(x) != hash.end())
                {
                    if (hash[x])
                        --hash[x];
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            string key{x};
            if (flag)
                res.push_back(key);
        }
        return res;
    }
};