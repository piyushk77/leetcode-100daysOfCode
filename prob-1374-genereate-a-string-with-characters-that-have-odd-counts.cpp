#include <string>
using namespace std;

class Solution
{
public:
    string generateTheString(int n)
    {
        string ans{};
        if (n % 2)
        {
            for (int i{1}; i <= n; ++i)
                ans += 'a';
        }
        else
        {
            for (int i{1}; i < n; ++i)
                ans += 'a';
            ans += 'b';
        }
        return ans;
    }
};