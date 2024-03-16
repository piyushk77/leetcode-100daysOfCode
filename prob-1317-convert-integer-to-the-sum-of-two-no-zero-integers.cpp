#include <vector>
using namespace std;

class Solution
{
public:
    inline bool containZero(int num)
    {
        while (num)
        {
            int digit{num % 10};
            if (!digit)
                return true;
            num /= 10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n)
    {
        vector<int> res;
        for (int i{1}; i < n; ++i)
        {
            if (containZero(i))
                continue;
            if (containZero(n - i))
                continue;
            res = {i, n - i};
            break;
        }
        return res;
    }
};