#include <string>
using namespace std;

class Solution
{
public:
    string finalString(string s)
    {
        string ans{};
        bool inv{};
        for (auto x : s)
        {
            if (x == 'i')
            {
                inv = !inv;
                continue;
            }

            if (!inv)
            {
                ans += x;
            }
            else
            {
                ans = x + ans;
            }
        }

        string rev{};
        if (inv)
        {
            for (int i{static_cast<int>(ans.size()) - 1}; i >= 0; --i)
            {
                rev += ans[i];
            }
            return rev;
        }
        return ans;
    }
};