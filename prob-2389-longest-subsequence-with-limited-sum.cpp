#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        int n{static_cast<int>(nums.size())};
        int m{static_cast<int>(queries.size())};
        sort(nums.begin(), nums.end());
        long long prefixSum{};
        vector<long long> prefix(n);
        for (int i{}; i < n; ++i)
        {
            prefixSum += nums[i];
            prefix[i] = prefixSum;
        }
        vector<int> answer(m);
        for (int i{}; i < m; ++i)
        {
            auto itr{upper_bound(prefix.begin(), prefix.end(), queries[i])};
            answer[i] = itr - prefix.begin();
        }
        return answer;
    }
};