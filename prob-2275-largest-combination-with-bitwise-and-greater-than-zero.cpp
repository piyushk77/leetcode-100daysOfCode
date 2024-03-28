#include <vector>
using namespace std;

class Solution
{
public:
    inline void countOnes(vector<int> &bitCount, int x)
    {
        unsigned int mask{0b1000'0000'0000'0000'0000'0000'0000'0000};
        for (int i{}; i < bitCount.size(); ++i)
        {
            unsigned int bit{(mask >> i) & x};
            if (bit)
                ++bitCount[i];
        }
    }
    int largestCombination(vector<int> &candidates)
    {
        const int varSize{sizeof(int) * 8};
        int max{};
        vector<int> bitCount(varSize);
        for (auto x : candidates)
            countOnes(bitCount, x);
        for (auto x : bitCount)
            if (max < x)
                max = x;
        return max;
    }
};