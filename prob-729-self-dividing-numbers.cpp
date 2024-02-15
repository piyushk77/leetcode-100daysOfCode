#include <vector>
using namespace std;

class Solution
{
public:
    bool isSelfDividing(int num)
    {
        int temp{num};
        while (temp)
        {
            int digit{temp % 10};
            if (!digit || num % digit != 0)
                return false;
            temp /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> res;
        for (int num{left}; num <= right; ++num)
        {
            if (isSelfDividing(num))
                res.push_back(num);
        }
        return res;
    }
};