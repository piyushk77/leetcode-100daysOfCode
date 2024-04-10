#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    double round(double var)
    {
        double value = (int)(var * 100 + .5);
        return (double)value / 100;
    }
    bool isBoomerang(vector<vector<int>> &points)
    {
        double x1{static_cast<double>(points[0][0])},
            y1{static_cast<double>(points[0][1])};
        double x2{static_cast<double>(points[1][0])},
            y2{static_cast<double>(points[1][1])};
        double x3{static_cast<double>(points[2][0])},
            y3{static_cast<double>(points[2][1])};

        if (x1 == x2)
        {
            if (y1 == y2)
                return false;
        }
        if (x2 == x3)
        {
            if (y2 == y3)
                return false;
        }
        if (x3 == x1)
        {
            if (y3 == y1)
                return false;
        }

        // making the line equation
        double m{(y1 - y2) / (x1 - x2)};
        double c{y1 - m * x1};

        if (isinf(m))
        {
            if (x3 != x1)
                return true;
            return false;
        }

        if (round(y3) == round(m * x3 + c))
            return false;

        return true;
    }
};