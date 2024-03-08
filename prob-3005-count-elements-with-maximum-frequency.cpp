#include <vector>
using namespace std;

class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        vector<int> hashMap(100);
        int max{};
        for (auto x : nums)
        {
            ++hashMap[x - 1];
            if (max < hashMap[x - 1])
                max = hashMap[x - 1];
        }
        int sum{};
        for (auto x : hashMap)
        {
            if (x == max)
                sum += x;
        }
        return sum;
    }
};