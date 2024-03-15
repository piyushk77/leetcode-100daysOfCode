#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target)
    {
        int mainDistance{abs(target[0]) + abs(target[1])};
        for (auto ghost : ghosts)
        {
            int ghostReach{abs(target[0] - ghost[0]) +
                           abs(target[1] - ghost[1])};
            if (ghostReach <= mainDistance)
                return false;
        }
        return true;
    }
};