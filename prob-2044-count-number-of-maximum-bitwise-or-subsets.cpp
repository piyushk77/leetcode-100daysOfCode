#include <vector>
using namespace std;

class Solution
{
public:
    int countMaxOrSubsets(vector<int> &nums)
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

        int maxOr{};
        vector<int> orList;
        for (auto x : powerSet)
        {
            int currentOr{};
            for (auto y : x)
            {
                currentOr |= y;
            }
            orList.push_back(currentOr);
            if (maxOr < currentOr)
                maxOr = currentOr;
        }

        int count{};
        for (auto x : orList)
        {
            if (x == maxOr)
                ++count;
        }

        return count;
    }
};