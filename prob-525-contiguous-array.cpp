#include <vector>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int sum{}, min{}, max{INT_MIN};
        vector<int> prefixSum;
        for (auto x : nums)
        {
            if (x == 0)
                --sum;
            else
                ++sum;
            prefixSum.push_back(sum);
            if (min > sum)
                min = sum;
            if (max < sum)
                max = sum;
        }
        int maxLen{};
        for (int i{static_cast<int>(prefixSum.size()) - 1}; i >= 0; --i)
        {
            if (prefixSum[i] == 0)
            {
                maxLen = i + 1;
                break;
            }
        }
        vector<vector<int>> hashTable(max - min + 1, {-1, -1});
        for (int i{}; i < prefixSum.size(); ++i)
        {
            int index{prefixSum[i] - min};
            if (hashTable[index][0] == -1)
            {
                hashTable[index][0] = i;
                hashTable[index][1] = i;
            }
            else if (hashTable[index][1] < i)
            {
                hashTable[index][1] = i;
            }
        }
        for (auto x : hashTable)
        {
            int len{x[1] - x[0]};
            if (maxLen < len)
                maxLen = len;
        }
        return maxLen;
    }
};