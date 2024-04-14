#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string removeStars(string s)
    {
        vector<char> strStack;
        for (auto x : s)
        {
            if (x == '*')
                strStack.pop_back();
            else
                strStack.push_back(x);
        }
        string ans{};
        for (auto x : strStack)
            ans += x;
        return ans;
    }
};