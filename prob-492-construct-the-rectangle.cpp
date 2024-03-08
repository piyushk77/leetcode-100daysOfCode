#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        int sqRoot{static_cast<int>(sqrt(area))};
        for (int i{sqRoot}; i >= 1; --i)
        {
            if (area % i == 0)
            {
                int x{i};
                int y{area / i};
                return {max(x, y), min(x, y)};
            }
        }
        return {-1, -1};
    }
};