#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<double>> coordinates;
        for (auto x : points)
        {
            vector<double> group;
            group.push_back(x[0]);
            group.push_back(x[1]);
            group.push_back(sqrt(pow(x[0], 2) + pow(x[1], 2)));
            coordinates.push_back(group);
        }
        sort(coordinates.begin(), coordinates.end(),
             [](const vector<double> &a, const vector<double> &b)
             {
                 return a.back() < b.back();
             });
        vector<vector<int>> result;
        for (int i{0}; i < k; ++i)
        {
            vector<int> point;
            point.push_back(static_cast<int>(coordinates[i][0]));
            point.push_back(static_cast<int>(coordinates[i][1]));
            result.push_back(point);
        }
        return result;
    }
};