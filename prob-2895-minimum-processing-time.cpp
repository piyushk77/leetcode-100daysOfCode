#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minProcessingTime(vector<int> &processorTime, vector<int> &tasks)
    {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end(), greater<int>());
        int i{};
        int maxTime;
        for (auto x : processorTime)
        {
            int first{x + tasks[i]};
            int second{x + tasks[++i]};
            int third{x + tasks[++i]};
            int fourth{x + tasks[++i]};
            int time{max(max(first, second), max(third, fourth))};
            ++i;
            if (maxTime < time)
                maxTime = time;
        }
        return maxTime;
    }
};