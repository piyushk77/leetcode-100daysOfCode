#include <vector>
using namespace std;

class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int time{};
        while (tickets[k])
        {
            for (int i{}; i < tickets.size(); ++i)
            {
                if (tickets[i] == 0)
                    continue;
                else if (i == k)
                {
                    ++time;
                    --tickets[i];
                    if (!tickets[i])
                        return time;
                }
                else
                {
                    ++time;
                    --tickets[i];
                }
            }
        }
        return -1;
    }
};