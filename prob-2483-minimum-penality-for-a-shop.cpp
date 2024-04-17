#include <string>
#include <climits>
using namespace std;

class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int ycount{}, ncount{};
        for (auto x : customers)
            if (x == 'Y')
                ++ycount;
        int penality{};
        int min{INT_MAX};
        int hour{};
        for (int i{}; i <= customers.size(); ++i)
        {
            penality = ycount + ncount;
            if (min > penality)
            {
                min = penality;
                hour = i;
            }
            if (i < customers.size() && customers[i] == 'Y')
                --ycount;
            else if (i < customers.size())
            {
                ++ncount;
            }
        }
        return hour;
    }
};