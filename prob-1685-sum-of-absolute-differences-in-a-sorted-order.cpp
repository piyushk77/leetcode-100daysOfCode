#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        long long total;
        for (auto x : nums)
        {
            total += x;
        }
        int n{static_cast<int>(nums.size())};
        long long leftSum{}, rightSum{total};
        vector<int> result;
        for (int i{}; i < n; ++i)
        {
            leftSum += nums[i];
            rightSum -= nums[i];
            int absoluteSum{};
            absoluteSum = (2 * i - n + 2) * nums[i] - leftSum + rightSum;
            result.push_back(absoluteSum);
        }
        return result;
    }
};