#include <string>
using namespace std;

class Solution
{
public:
    int balancedStringSplit(string s)
    {
        int lCount{}, rCount{};
        int count{};
        for (auto x : s)
        {
            if (x == 'L')
            {
                ++lCount;
                if (lCount == rCount)
                {
                    ++count;
                    lCount = rCount = 0;
                }
            }
            else
            {
                ++rCount;
                if (rCount == lCount)
                {
                    ++count;
                    rCount = lCount = 0;
                }
            }
        }
        return count;
    }
};