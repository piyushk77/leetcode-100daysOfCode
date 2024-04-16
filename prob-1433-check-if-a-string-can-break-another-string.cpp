#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool checkIfCanBreak(string s1, string s2)
    {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        bool flag1{}, flag2{};
        if (s1[0] <= s2[0])
        {
            bool flag{true};
            for (int i{}; i < s1.size(); ++i)
            {
                if (s1[i] > s2[i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return true;
        }
        if (s2[0] <= s1[0])
        {
            bool flag{true};
            for (int i{}; i < s1.size(); ++i)
            {
                if (s2[i] > s1[i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return true;
        }

        return false;
    }
};