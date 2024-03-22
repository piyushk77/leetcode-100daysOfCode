#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        vector<int> runSum;
        int prefixSum{};
        for (auto x : nums)
        {
            prefixSum += x;
            runSum.push_back(prefixSum);
        }
        return runSum;
    }
};