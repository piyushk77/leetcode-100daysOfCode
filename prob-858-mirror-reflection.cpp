#include <cmath>
using namespace std;

class Solution
{
public:
    int hcf(int a, int b)
    {
        int x{min(a, b)};
        int y{max(a, b)};
        if (y % x == 0)
            return x;
        return hcf(y % x, x);
    }
    int mirrorReflection(int p, int q)
    {
        int gcf{hcf(p, q)};
        if ((p / gcf) % 2 == 0)
            return 2;
        if ((q / gcf) % 2 == 0)
            return 0;
        return 1;
    }
};