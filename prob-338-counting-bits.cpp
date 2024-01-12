#include <vector>
using namespace std;
class Solution
{
public:
    int oneBits(int n)
    {
        int ones{};
        while (n)
        {
            int rem{n % 2};
            n /= 2;
            if (rem)
                ++ones;
        }
        return ones;
    }
    vector<int> countBits(int n)
    {
        vector<int> ans;
        for (int i{}; i <= n; ++i)
        {
            ans.push_back(oneBits(i));
        }
        return ans;
    }
};