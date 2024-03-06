#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    vector<int> pathInZigZagTree(int label)
    {
        vector<vector<int>> chart;

        // Calculate the chart
        int p{}, low{}, high{};
        while (high < label)
        {
            low = pow(2, p);
            high += low;
            chart.push_back({low, high});
            ++p;
        }

        // Reverse track the path
        int i{static_cast<int>(chart.size()) - 1};
        vector<int> res;
        while (i >= 0)
        {
            if (i % 2 == 0)
            {
                int pair{label - chart[i][0] + 1};
                if (pair % 2)
                    ++pair;
                res.push_back(label);
                pair /= 2;
                --i;
                if (i < 0)
                    break;
                label = chart[i][1] - pair + 1;
            }
            else
            {
                int pair{chart[i][1] - label + 1};
                if (pair % 2)
                    ++pair;
                res.push_back(label);
                pair /= 2;
                --i;
                if (i < 0)
                    break;
                label = chart[i][0] + pair - 1;
            }
        }

        vector<int> path;
        for (int j{static_cast<int>(res.size()) - 1}; j >= 0; --j)
            path.push_back(res[j]);

        return path;
    }
};