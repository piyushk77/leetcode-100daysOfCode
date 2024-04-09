#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        // create the line equation y = mx + c:
        double x1{static_cast<double>(coordinates[0][0])};
        double x2{static_cast<double>(coordinates[1][0])};
        double y1{static_cast<double>(coordinates[0][1])};
        double y2{static_cast<double>(coordinates[1][1])};
        double m{(y2 - y1) / (x2 - x1)};
        if (isinf(m))
        {
            int check{coordinates[0][0]};
            for (auto p : coordinates)
                if (p[0] != check)
                    return false;
            return true;
        }
        double c{y1 - m * x1};

        for (auto p : coordinates)
        {
            int x{p[0]};
            int y{p[1]};
            if (y != (m * x + c))
                return false;
        }
        return true;
    }
};