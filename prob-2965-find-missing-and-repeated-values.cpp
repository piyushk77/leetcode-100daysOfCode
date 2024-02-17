#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        vector<int> linear;
        for (auto x : grid)
        {
            for (auto y : x)
                linear.push_back(y);
        }

        sort(linear.begin(), linear.end());

        int repeating{}, missing{};
        bool found{false};
        for (int i{1}; i < linear.size(); ++i)
        {
            if (linear[i] == linear[i - 1])
            {
                repeating = linear[i];
                continue;
            }
            if (!found && linear[i] != linear[i - 1] + 1)
            {
                missing = linear[i - 1] + 1;
                found = true;
            }
        }

        if (missing == 0 && linear[0] == 1)
        {
            missing = linear.back() + 1;
        }
        else if (missing == 0)
        {
            missing = 1;
        }

        return {repeating, missing};
    }
};