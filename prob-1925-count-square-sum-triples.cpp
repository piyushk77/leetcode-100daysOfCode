#include <cmath>
using namespace std;

class Solution
{
public:
    int countTriples(int n)
    {
        int count{};
        for (int a{1}; a <= n; ++a)
        {
            for (int b{1}; b <= n; ++b)
            {
                double c{sqrt(a * a + b * b)};
                int check{static_cast<int>(c)};
                if (check - c == 0 && 1 <= c && c <= n)
                    ++count;
            }
        }
        return count;
    }
};