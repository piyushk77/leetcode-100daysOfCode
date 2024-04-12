#include <vector>
using namespace std;

class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        const int SIZE{10000};
        vector<int> hashTable(SIZE + 1);
        for (auto x : nums)
        {
            ++hashTable[x];
            if (hashTable[x] > 1)
                return x;
        }
        return -1;
    }
};