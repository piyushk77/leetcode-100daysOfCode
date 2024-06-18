#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {

        int n{static_cast<int>(difficulty.size())}; // Number of jobs
        int m{static_cast<int>(worker.size())};     // Number of workers;

        // Pair up the difficulty with profit
        vector<pair<int, int>> jobs;
        for (int i{}; i < n; ++i)
            jobs.push_back({profit[i], difficulty[i]});

        // Sort these pairs based on profits in descending order
        sort(jobs.begin(), jobs.end(), greater<pair<int, int>>());

        // Sort the worker ability in descending order
        sort(worker.begin(), worker.end(), greater<int>());

        // Use two pointers to assign the work and check profit sum
        int i{}, j{};
        int profitSum{};
        while (i < m && j < n)
        {
            while (i < m && jobs[j].second <= worker[i])
            {
                profitSum += jobs[j].first;
                ++i;
            }
            ++j;
        }

        // Return the maximum profit
        return profitSum;
    }
};