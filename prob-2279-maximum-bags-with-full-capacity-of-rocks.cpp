#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks,
                    int additionalRocks)
    {
        vector<int> space;
        for (int i{}; i < capacity.size(); ++i)
        {
            space.push_back(capacity[i] - rocks[i]);
        }

        sort(space.begin(), space.end());

        int bags{};
        for (auto x : space)
        {
            if (additionalRocks >= x)
            {
                additionalRocks -= x;
                ++bags;
            }
            else
                break;
        }
        return bags;
    }
};