#include <vector>
using namespace std;

class Solution
{
public:
    int averageValue(vector<int> &nums)
    {
        int count{}, sum{};
        for (auto x : nums)
        {
            if (x % 2 == 0 && x % 3 == 0)
            {
                ++count;
                sum += x;
            }
        }
        if (count == 0)
            return 0;
        else
            return (sum / count);
    }
};