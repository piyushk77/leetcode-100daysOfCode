#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int count{};
        for (auto x : words)
        {
            bool flag{true};
            for (int i{}; i < pref.size(); ++i)
                if (x[i] != pref[i])
                {
                    flag = false;
                    break;
                }
            if (flag)
                ++count;
        }
        return count;
    }
};