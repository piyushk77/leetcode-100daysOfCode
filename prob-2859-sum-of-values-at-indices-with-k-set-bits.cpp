#include <vector>
using namespace std;

class Solution
{
public:
    int setBits(int num)
    {
        int mask{1};
        const int size{32};
        int sum{};
        for (int i{}; i < size; ++i)
        {
            sum += static_cast<int>(static_cast<bool>(num & (mask << i)));
        }
        return sum;
    }
    int sumIndicesWithKSetBits(vector<int> &nums, int k)
    {
        int sum{};
        for (int i{}; i < nums.size(); ++i)
        {
            if (setBits(i) == k)
            {
                sum += nums[i];
            }
        }
        return sum;
    }
};