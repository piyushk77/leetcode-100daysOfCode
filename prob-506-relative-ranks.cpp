#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        int players{static_cast<int>(score.size())};
        vector<vector<int>> mapScore(players);
        for (int i{}; i < players; ++i)
        {
            mapScore[i] = {score[i], i};
        }
        sort(mapScore.begin(), mapScore.end(), greater<vector<int>>());
        vector<string> ranks(players);

        for (int i{0}; i < players; ++i)
        {
            if (i == 0)
                ranks[mapScore[0][1]] = "Gold Medal";
            else if (i == 1)
                ranks[mapScore[1][1]] = "Silver Medal";
            else if (i == 2)
                ranks[mapScore[2][1]] = "Bronze Medal";
            else
                ranks[mapScore[i][1]] = to_string(i + 1);
        }
        return ranks;
    }
};