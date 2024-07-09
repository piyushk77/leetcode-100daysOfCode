#include <vector>
using namespace std;

class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        int n{static_cast<int>(customers.size())};
        long long currTime{customers[0][0]};
        long long totalWait{};
        for (auto cust : customers)
        {
            if (currTime < cust[0])
                currTime = cust[0];
            currTime += cust[1];
            totalWait += currTime - cust[0];
        }
        return totalWait / static_cast<double>(n);
    }
};