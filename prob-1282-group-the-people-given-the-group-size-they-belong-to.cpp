#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        int n{static_cast<int>(groupSizes.size())};
        vector<int> hashGroupFreq(n);
        vector<vector<int>> hashPeople(n);
        for (int i{}; i < n; ++i)
        {
            ++hashGroupFreq[groupSizes[i] - 1];
            hashPeople[groupSizes[i] - 1].push_back(i);
        }
        for (int i{}; i < n; ++i)
        {
            hashGroupFreq[i] /= i + 1;
        }

        vector<vector<int>> groupList;
        for (int i{}; i < n; ++i)
        {
            if (!hashGroupFreq[i])
                continue;
            for (int j{1}; j <= hashGroupFreq[i]; ++j)
            {
                vector<int> group;
                for (int f{1}; f <= i + 1; ++f)
                {
                    group.push_back(hashPeople[i].back());
                    hashPeople[i].pop_back();
                }
                groupList.push_back(group);
            }
        }

        return groupList;
    }
};