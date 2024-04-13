#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        sort(tasks.begin(), tasks.end());
        int rounds{};
        for (int i{}; i < tasks.size(); ++i)
        {
            int diff{tasks[i]};
            int count{};
            while (i < tasks.size() && tasks[i] == diff)
            {
                ++count;
                ++i;
            }
            --i;
            if (count <= 1)
                return -1;
            else if (count % 3 == 0)
                rounds += (count / 3);
            else
                rounds += ((count / 3) + 1);
        }
        return rounds;
    }
};