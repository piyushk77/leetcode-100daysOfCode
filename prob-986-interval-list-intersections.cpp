#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList,
                                             vector<vector<int>> &secondList)
    {
        vector<vector<int>> intersect;
        for (int i{}; i < firstList.size(); ++i)
        {
            int fStart{firstList[i][0]};
            int fEnd{firstList[i][1]};
            for (auto x : secondList)
            {
                int sStart{x[0]};
                int sEnd{x[1]};
                int finalStart{};
                int finalEnd{};
                if (sStart > fEnd)
                    break;
                if (fStart <= sStart)
                {
                    finalEnd = (fEnd < sEnd ? fEnd : sEnd);
                    finalStart = sStart;
                }
                else
                {
                    if (sEnd < fStart)
                        continue;
                    finalStart = fStart;
                    finalEnd = (fEnd < sEnd ? fEnd : sEnd);
                }
                intersect.push_back({finalStart, finalEnd});
            }
        }
        return intersect;
    }
};