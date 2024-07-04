#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    bool areOccurrencesEqual(string s)
    {
        unordered_map<char, int> umap;
        for (auto x : s)
        {
            umap[x]++;
        }
        int val{umap[s[0]]};
        for (auto x : s)
        {
            if (umap[x] != val)
                return false;
        }
        return true;
    }
};