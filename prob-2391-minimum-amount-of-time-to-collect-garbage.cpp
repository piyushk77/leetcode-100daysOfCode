#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        int n{static_cast<int>(garbage.size())};
        int lastG{-1}, lastM{-1}, lastP{-1};
        int garb{};
        for (int i{}; i < n; ++i)
        {
            for (int j{}; j < garbage[i].size(); ++j)
            {
                if (garbage[i][j] == 'G')
                {
                    ++garb;
                    lastG = i;
                }
                else if (garbage[i][j] == 'M')
                {
                    ++garb;
                    lastM = i;
                }
                else
                {
                    ++garb;
                    lastP = i;
                }
            }
        }

        int sum{};
        vector<int> travelPrefix;
        for (auto x : travel)
        {
            sum += x;
            travelPrefix.push_back(sum);
        }

        int time{garb};
        if (lastM > 0)
            time += travelPrefix[lastM - 1];
        if (lastG > 0)
            time += travelPrefix[lastG - 1];
        if (lastP > 0)
            time += travelPrefix[lastP - 1];

        return time;
    }
};