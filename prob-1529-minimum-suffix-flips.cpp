#include <string>
using namespace std;

class Solution
{
public:
    int minFlips(string target)
    {
        int count{};
        char flag{'0'};
        for (auto x : target)
        {
            if (x != flag)
            {
                ++count;
                if (flag == '0')
                    flag = '1';
                else
                    flag = '0';
            }
        }
        return count;
    }
};