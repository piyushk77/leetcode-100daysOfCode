#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k)
    {
        vector<int> hashUAM(k);
        sort(logs.begin(), logs.end());
        for (int i{}; i < logs.size(); ++i)
        {
            int id{logs[i][0]};
            int prevTime{-1}, uam{};
            while (i < logs.size() && id == logs[i][0])
            {
                if (prevTime != logs[i][1])
                {
                    ++uam;
                    prevTime = logs[i][1];
                }
                ++i;
            }
            --i;
            ++hashUAM[uam - 1];
        }
        return hashUAM;
    }
};