#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> decrementCool(vector<int> coolDown)
    {
        for (int i{}; i < coolDown.size(); ++i)
        {
            if (coolDown[i])
                --coolDown[i];
        }
        return coolDown;
    }
    int selectTask(vector<int> taskFreq, vector<int> coolDown)
    {
        int max{-1};
        int maxIndex{-1};
        bool remaining{};
        for (int i{}; i < taskFreq.size(); ++i)
        {
            if (coolDown[i] == 0 && taskFreq[i] != 0)
                if (max < taskFreq[i])
                {
                    max = taskFreq[i];
                    maxIndex = i;
                }
            if (!taskFreq[i])
                remaining = true;
        }

        if (maxIndex == -1)
        {
            if (remaining)
                return -1;
            else
                return -2;
        }

        return maxIndex;
    }

    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> taskFreq(static_cast<int>('Z'));
        vector<int> coolDown(static_cast<int>('Z'));
        // calculate the frequencies of all the tasks
        int totalTasks{};
        for (auto x : tasks)
        {
            ++taskFreq[static_cast<int>(x) - 1];
            ++totalTasks;
        }
        int count{};
        while (totalTasks)
        {
            int index{selectTask(taskFreq, coolDown)};
            if (index == -1)
            {
                ++count;
                coolDown = decrementCool(coolDown);
                continue;
            }
            if (index == -2)
                return count;
            --taskFreq[index];
            coolDown = decrementCool(coolDown);
            coolDown[index] = n;
            ++count;
            --totalTasks;
        }
        return count;
    }
};