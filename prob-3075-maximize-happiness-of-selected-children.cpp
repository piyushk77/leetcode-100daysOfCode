#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long sum{};
        for (int i{}; i < k; ++i)
        {
            sum += (happiness[i] - i > 0) ? (happiness[i] - i) : 0;
        }
        return sum;
    }
};