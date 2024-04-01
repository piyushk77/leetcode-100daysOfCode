#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        vector<int> allowedHash(static_cast<int>('z'));
        for (auto x : allowed)
            allowedHash[(static_cast<int>(x)) - 1] = 1;
        int count{};
        for (auto x : words)
        {
            bool flag{true};
            for (auto y : x)
            {
                if (!allowedHash[(static_cast<int>(y)) - 1])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ++count;
        }
        return count;
    }
};