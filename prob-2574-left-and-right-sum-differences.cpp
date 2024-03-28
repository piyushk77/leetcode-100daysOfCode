#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &nums)
    {
        vector<int> leftSum;
        int sum{};
        for (auto x : nums)
        {
            leftSum.push_back(sum);
            sum += x;
        }
        sum = 0;
        vector<int> temp;
        for (int i{static_cast<int>(nums.size()) - 1}; i >= 0; --i)
        {
            temp.push_back(sum);
            sum += nums[i];
        }
        vector<int> rightSum;
        for (int i{static_cast<int>(nums.size()) - 1}; i >= 0; --i)
        {
            rightSum.push_back(temp[i]);
        }
        vector<int> answer;
        for (int i{}; i < leftSum.size(); ++i)
            answer.push_back(abs(leftSum[i] - rightSum[i]));
        return answer;
    }
};