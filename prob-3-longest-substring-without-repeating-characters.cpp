#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n{static_cast<int>(s.size())};
        int left{}, right{};
        int maxLen{}, count{};
        unordered_set<int> hash;
        while (right < n)
        {
            if (hash.find(s[right]) != hash.end())
            {
                if (maxLen < count)
                    maxLen = count;
                while (s[left] != s[right])
                {
                    hash.erase(s[left]);
                    ++left;
                    --count;
                }
                hash.erase(s[left]);
                ++left;
                --count;
            }
            else
            {
                hash.insert(s[right]);
                ++count;
                ++right;
            }
        }
        if (maxLen < count)
            maxLen = count;
        return maxLen;
    }
};