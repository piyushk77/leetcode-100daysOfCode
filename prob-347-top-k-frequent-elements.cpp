#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        const int sizeConst{20000};
        const int fact{10000};
        vector<vector<int>> hashTable(sizeConst + 1, vector<int>(2));
        for (auto x : nums)
        {
            ++hashTable[x + fact][0];
            hashTable[x + fact][1] = x;
        }

        sort(hashTable.begin(), hashTable.end());
        int len{static_cast<int>(hashTable.size())};
        vector<int> ans;
        for (int i{len - 1}; i >= len - k; --i)
            ans.push_back(hashTable[i][1]);
        return ans;
    }
};