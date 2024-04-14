#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int partitionString(string s)
    {
        vector<int> hashStr(static_cast<int>('z') + 1);
        int count{};
        for (int i{}; i < s.size(); ++i)
        {
            if (!hashStr[s[i]])
                ++hashStr[s[i]];
            else
            {
                vector<int> reset(static_cast<int>('z') + 1);
                hashStr = reset;
                ++count;
                --i;
            }
        }
        ++count;
        return count;
    }
};