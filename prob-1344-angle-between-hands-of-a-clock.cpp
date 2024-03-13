#include <cmath>
using namespace std;

class Solution
{
public:
    double angleClock(int hour, int minutes)
    {
        minutes += (hour * 60);
        double angle{5.5 * minutes};
        int i{};
        while (360 * i <= angle)
            ++i;
        --i;
        angle -= (360 * i);
        return min(360 - angle, angle);
    }
};