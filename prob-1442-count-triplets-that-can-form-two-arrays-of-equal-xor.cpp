#include <vector>
using namespace std;

class Solution
{
public:
    int countTriplets(vector<int> &arr)
    {
        int len{static_cast<int>(arr.size())};
        int count{};
        for (int i{}; i < len - 1; ++i)
        {
            int xorSum{arr[i]};
            int n{i + 1};
            while (n < len)
            {
                xorSum ^= arr[n];
                if (xorSum == 0)
                {
                    count += (n - i);
                }
                ++n;
            }
        }
        return count;
    }
};