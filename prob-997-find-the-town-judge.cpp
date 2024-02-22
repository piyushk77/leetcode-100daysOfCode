#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        if (trust.size() == 0)
        {
            if (n > 1)
                return -1;
            else
                return 1;
        }

        vector<int> trustList;
        for (auto x : trust)
        {
            trustList.push_back(x[0]);
        }
        sort(trustList.begin(), trustList.end());
        // make list unique
        vector<int> unique;
        for (int i{}; i < trustList.size(); ++i)
        {
            int u{trustList[i]};
            while (i < trustList.size() && u == trustList[i])
                ++i;
            --i;
            unique.push_back(u);
        }

        trustList = unique;

        // find the judge
        int sum{};
        for (auto x : trustList)
        {
            sum += x;
        }
        int total{n * (n + 1) / 2};
        int judge{total - sum};
        if (!judge)
            return -1;

        for (auto x : trust)
        {
            if (x[1] == judge)
                total -= x[0];
        }

        if (total == judge)
            return judge;
        return -1;
    }
};