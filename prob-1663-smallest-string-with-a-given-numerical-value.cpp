#include <string>
using namespace std;

class Solution
{
public:
    string getSmallestString(int n, int k)
    {
        char start{'a' - 1};
        int fact{k - n + 1};
        int zeds{};
        int v{26};
        for (; v >= 1; --v)
        {
            if ((fact - v) >= 0 && (fact - v) % 25 == 0)
            {
                zeds = (fact - v) / 25;
                break;
            }
        }
        string ans{};
        for (int i{1}; i <= (n - zeds - 1); ++i)
            ans += 'a';
        ans += static_cast<char>(start + v);
        for (int i{1}; i <= zeds; ++i)
            ans += 'z';
        return ans;
    }
};