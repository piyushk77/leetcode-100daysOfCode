#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int countMatches(vector<vector<string>> &items, string ruleKey,
                     string ruleValue)
    {
        int setIndex{};
        if (ruleKey == "color")
            setIndex = 1;
        if (ruleKey == "name")
            setIndex = 2;
        int count{};
        for (auto x : items)
        {
            if (x[setIndex] == ruleValue)
                ++count;
        }
        return count;
    }
};