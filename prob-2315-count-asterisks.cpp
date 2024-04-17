#include <string>
using namespace std;

class Solution
{
public:
    int countAsterisks(string s)
    {
        bool flag{true};
        int count{};
        for (auto x : s)
        {
            if (x == '|')
            {
                flag = !flag;
            }
            if (x == '*' && flag)
                ++count;
        }
        return count;
    }
};