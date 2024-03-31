#include <vector>
using namespace std;

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int max{}, sum{};
        for (auto x : gain)
        {
            sum += x;
            if (max < sum)
                max = sum;
        }
        return max;
    }
};