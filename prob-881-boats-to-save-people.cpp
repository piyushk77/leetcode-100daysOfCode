#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());
        int len{static_cast<int>(people.size())};
        int i{}, j{len - 1};
        int count{};
        while (i < j)
        {
            if (people[i] == -1)
            {
                ++i;
                continue;
            }
            if (people[j] == -1)
            {
                --j;
                continue;
            }
            if ((people[i] + people[j]) <= limit)
            {
                people[i] = -1;
                people[j] = -1;
                ++count;
                ++i;
                --j;
            }
            else
                --j;
        }

        for (auto x : people)
            if (x != -1)
                ++count;
        return count;
    }
};