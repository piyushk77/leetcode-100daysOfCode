#include <vector>
using namespace std;

class Solution
{
public:
    vector<long long> findPrefixScore(vector<int> &nums)
    {
        vector<long long> scores;
        int currentMax{};
        long long sum{};
        for (auto x : nums)
        {
            if (currentMax < x)
                currentMax = x;
            sum += (x + currentMax);
            scores.push_back(sum);
        }
        return scores;
    }
};