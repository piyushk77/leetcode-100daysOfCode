#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumPushes(string word)
    {
        vector<int> hashTable(static_cast<int>('z') + 1);
        for (auto x : word)
            ++hashTable[x];
        sort(hashTable.begin(), hashTable.end(), greater<int>());
        int press{1};
        int count{};
        int total{};
        for (auto x : hashTable)
        {
            ++count;
            if (!x)
                break;
            total += (x * press);
            if (count == 8)
            {
                count = 0;
                ++press;
            }
        }
        return total;
    }
};