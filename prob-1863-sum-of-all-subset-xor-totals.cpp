#include <vector>
using namespace std;

class Solution
{
public:
    int subsetXORSum(vector<int> &nums)
    {
        vector<vector<int>> powerSet{{}};
        for (auto x : nums)
        {
            int n{static_cast<int>(powerSet.size())};
            for (int i{}; i < n; ++i)
            {
                vector<int> subSet{powerSet[i]};
                subSet.push_back(x);
                powerSet.push_back(subSet);
            }
        }

        int sum{};
        for (auto x : powerSet)
        {
            int xorSum{};
            for (auto y : x)
                xorSum ^= y;
            sum += xorSum;
        }
        return sum;
    }
};