#include <cmath>
using namespace std;
class Solution
{
public:
    int arrangeCoins(int n)
    {
        long coins{n};
        int rows{static_cast<int>((pow(8 * coins + 1, 0.5) - 1) / 2)};
        return rows;
    }
};