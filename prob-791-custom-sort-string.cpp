#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string customSortString(string order, string s)
    {
        vector<int> hashMap(static_cast<int>('z'));
        for (auto x : s)
        {
            ++hashMap[static_cast<int>(x) - 1];
        }

        string res;
        for (auto x : order)
        {
            for (int i{1}; i <= hashMap[static_cast<int>(x) - 1]; ++i)
            {
                res += x;
            }
            hashMap[static_cast<int>(x) - 1] = 0;
        }

        for (int i{}; i < hashMap.size(); ++i)
        {
            if (hashMap[i])
            {
                for (int j{1}; j <= hashMap[i]; ++j)
                {
                    res += static_cast<char>(i + 1);
                }
            }
        }

        return res;
    }
};