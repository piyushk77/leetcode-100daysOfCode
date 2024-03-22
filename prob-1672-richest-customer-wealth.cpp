#include <vector>
using namespace std;

class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int max{};
        for (auto customer : accounts)
        {
            int sum{};
            for (auto capital : customer)
            {
                sum += capital;
            }
            if (max < sum)
                max = sum;
        }
        return max;
    }
};