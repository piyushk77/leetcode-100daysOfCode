#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end());
        int n{static_cast<int>(points.size())};
        int max{};
        for (int i{}; i < n - 1; ++i)
        {
            if (max < (points[i + 1][0] - points[i][0]))
                max = points[i + 1][0] - points[i][0];
        }
        return max;
    }
};