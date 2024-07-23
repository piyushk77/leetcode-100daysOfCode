#include <vector>
#include <utility>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    static inline bool comp(pair<int, int> p1, pair<int, int> p2)
    {
        if (p1.second < p2.second)
            return true;
        if (p1.second == p2.second)
        {
            if (p1.first < p2.first)
                return false;
            return true;
        }
        return false;
    }
    vector<int> frequencySort(vector<int> &nums)
    {
        unordered_map<int, int> m;
        for (auto x : nums)
            m[x]++;
        int n{static_cast<int>(m.size())};
        vector<pair<int, int>> res(n);
        int i{};
        for (auto x : m)
        {
            res[i] = x;
            ++i;
        }
        sort(res.begin(), res.end(), comp);
        i = 0;
        for (auto x : res)
            for (int k{1}; k <= x.second; ++k)
                nums[i++] = x.first;
        return nums;
    }
};