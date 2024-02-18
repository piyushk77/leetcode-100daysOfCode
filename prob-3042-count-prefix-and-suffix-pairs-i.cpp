#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isPrefixAndSuffix(string str1, string str2)
    {
        int len1{static_cast<int>(str1.size())};
        int len2{static_cast<int>(str2.size())};
        if (len2 < len1)
            return false;
        for (int i{}; i < len1; ++i)
        {
            if (str1[i] != str2[i])
                return false;
        }
        for (int i{len1 - 1}, j{len2 - 1}; i >= 0; --i, --j)
        {
            if (str1[i] != str2[j])
                return false;
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string> &words)
    {
        int count{};
        for (int i{}; i < words.size(); ++i)
        {
            string pattern{words[i]};
            for (int j{i + 1}; j < words.size(); ++j)
            {
                if (isPrefixAndSuffix(pattern, words[j]))
                    ++count;
            }
        }
        return count;
    }
};