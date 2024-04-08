#include <vector>
using namespace std;

class Solution
{
public:
    int countDigits(int num)
    {
        int factor{10};
        int digits{};
        while (num / factor)
            ++digits, factor *= 10;
        ++digits;
        return digits;
    }
    int findNumbers(vector<int> &nums)
    {
        int count{};
        for (auto x : nums)
        {
            if ((countDigits(x) % 2) == 0)
                ++count;
        }
        return count;
    }
};