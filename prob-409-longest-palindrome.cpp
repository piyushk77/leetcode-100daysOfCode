#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> hash;
        for (auto x : s)
        {
            if (hash.find(x) != hash.end())
                ++hash[x];
            else
                hash.insert(make_pair(x, 1));
        }

        int count{};
        bool flag{};
        for (auto h : hash)
        {
            if (h.second % 2 == 0)
                count += h.second;
            else
            {
                flag = true;
                count += (h.second - 1);
            }
        }
        if (flag)
            ++count;
        return count;
    }
};