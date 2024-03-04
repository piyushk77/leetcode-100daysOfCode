#include <vector>
using namespace std;

class Solution
{
public:
    double calcArea(vector<int> x, vector<int> y, vector<int> z)
    {
        double area{
            static_cast<double>((x[0] * (y[1] - z[1]) + y[0] * (z[1] - x[1]) +
                                 z[0] * (x[1] - y[1]))) /
            2};
        return area;
    }
    double largestTriangleArea(vector<vector<int>> &points)
    {
        int len{static_cast<int>(points.size())};
        double max{};
        for (int i{}; i < len; ++i)
        {
            for (int j{}; j < len; ++j)
            {
                for (int k{}; k < len; ++k)
                {
                    double area{calcArea(points[i], points[j], points[k])};
                    if (max < area)
                        max = area;
                }
            }
        }
        return max;
    }
};