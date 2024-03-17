#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals,
                               vector<int> &newInterval)
    {
        vector<vector<int>> res;
        // push untill the newInterval start time is less than current
        // interval's end time
        int i{};
        while (i < intervals.size() && intervals[i][1] < newInterval[0])
        {
            res.push_back(intervals[i]);
            ++i;
        }

        // find the start time of interval
        int start{};
        if (i == intervals.size())
            start = newInterval[0];
        else if (intervals[i][0] <= newInterval[0] &&
                 newInterval[0] <= intervals[i][1])
            start = intervals[i][0];
        else
            start = newInterval[0];

        // find the end time of interval
        int end{};
        while (i < intervals.size() && intervals[i][0] <= newInterval[1])
            ++i;
        if (i == 0)
        {
            end = newInterval[1];
        }
        else if (i == intervals.size())
        {
            if (intervals[i - 1][1] >= newInterval[1])
                end = intervals[i - 1][1];
            else
                end = newInterval[1];
        }
        else if (intervals[i - 1][1] < newInterval[1])
            end = newInterval[1];
        else
            end = intervals[i - 1][1];

        res.push_back({start, end});

        while (i < intervals.size())
        {
            res.push_back(intervals[i]);
            ++i;
        }

        return res;
    }
};