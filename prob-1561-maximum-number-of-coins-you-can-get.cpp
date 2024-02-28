#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        int n{static_cast<int>(piles.size()) / 3};
        sort(piles.begin(), piles.end(), greater<int>());
        int sum{};
        for (int i{1}, j{1}; i <= n; ++i, j += 2)
        {
            sum += piles[j];
        }
        return sum;
    }
};