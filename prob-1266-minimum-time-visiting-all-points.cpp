#include <vector>
using namespace std;

class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        int totalTime{};
        for (int i{0}; i < points.size() - 1; ++i)
        {
            int pointX{points[i][0]};
            int pointY{points[i][1]};

            int time{};

            if (i + 1 < points.size())
            {
                int nextX{points[i + 1][0]};
                int nextY{points[i + 1][1]};

                int unitX{nextX - pointX};
                int unitY{nextY - pointY};

                if (unitX < 0)
                    unitX *= -1;
                if (unitY < 0)
                    unitY *= -1;

                if (unitX > unitY)
                    time += unitX;
                else
                    time += unitY;
            }
            totalTime += time;
        }
        return totalTime;
    }
};