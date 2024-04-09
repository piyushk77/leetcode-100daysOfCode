#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums,
                                    vector<vector<int>> &queries)
    {
        int sum{};
        for (auto x : nums)
            if (x % 2 == 0)
                sum += x;
        vector<int> answer;
        for (auto q : queries)
        {
            if (nums[q[1]] % 2 == 0)
            {
                if (q[0] % 2 == 0)
                {
                    sum += q[0];
                    nums[q[1]] += q[0];
                }
                else
                {
                    sum -= nums[q[1]];
                    nums[q[1]] += q[0];
                }
            }
            else
            {
                if (q[0] % 2 == 0)
                {
                    nums[q[1]] += q[0];
                }
                else
                {
                    sum += (nums[q[1]] + q[0]);
                    nums[q[1]] += q[0];
                }
            }
            answer.push_back(sum);
        }
        return answer;
    }
};