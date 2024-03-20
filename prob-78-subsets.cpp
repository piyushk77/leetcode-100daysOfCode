#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> powerSet{{}};
        for (auto x : nums)
        {
            int n{static_cast<int>(powerSet.size())};
            for (int i{}; i < n; ++i)
            {
                vector<int> miniSet{powerSet[i]};
                miniSet.push_back(x);
                powerSet.push_back(miniSet);
            }
        }
        return powerSet;
    }
};